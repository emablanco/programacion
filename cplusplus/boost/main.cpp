#include <boost/asio.hpp>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <boost/filesystem.hpp>

using boost::asio::ip::tcp;

std::string read_file(const std::string& file_path) {
  std::ifstream file(file_path.c_str(), std::ios::in | std::ios::binary);
  if (!file) {
    return "";
  }

  std::ostringstream contents;
  contents << file.rdbuf();
  file.close();

  return contents.str();
}

int main() {
  boost::asio::io_service io_service;

  tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), 80));
  std::cout << "Listening on port 80\n";

  while (true) {
    tcp::socket socket(io_service);
    acceptor.accept(socket);

    boost::asio::streambuf request;
    boost::asio::read_until(socket, request, "\r\n\r\n");

    std::string message = "HTTP/1.0 200 OK\r\n";
    message += "Content-Type: text/html\r\n\r\n";
    message += "<html><body>";

    for (boost::filesystem::directory_iterator it("ema");
         it != boost::filesystem::directory_iterator(); ++it) {
      if (boost::filesystem::is_regular_file(it->path())) {
        std::string filename = it->path().filename().string();
        std::string file_contents = read_file(it->path().string());

        message += "<h2>" + filename + "</h2>";
        message += "<p>" + file_contents + "</p>";
      }
    }

    message += "</body></html>";
    boost::asio::write(socket, boost::asio::buffer(message));
  }

  return 0;
}

