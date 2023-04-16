# Set up the prompt

autoload -Uz promptinit
promptinit
prompt adam2

setopt histignorealldups sharehistory

# Use emacs keybindings even if our EDITOR is set to vi
bindkey -e

# Keep 1000 lines of history within the shell and save it to ~/.zsh_history:
HISTSIZE=1000
SAVEHIST=1000
HISTFILE=~/.zsh_history

# Use modern completion system
autoload -Uz compinit
compinit

zstyle ':completion:*' auto-description 'specify: %d'
zstyle ':completion:*' completer _expand _complete _correct _approximate
zstyle ':completion:*' format 'Completing %d'
zstyle ':completion:*' group-name ''
zstyle ':completion:*' menu select=2
eval "$(dircolors -b)"
zstyle ':completion:*:default' list-colors ${(s.:.)LS_COLORS}
zstyle ':completion:*' list-colors ''
zstyle ':completion:*' list-prompt %SAt %p: Hit TAB for more, or the character to insert%s
zstyle ':completion:*' matcher-list '' 'm:{a-z}={A-Z}' 'm:{a-zA-Z}={A-Za-z}' 'r:|[._-]=* r:|=* l:|=*'
zstyle ':completion:*' menu select=long
zstyle ':completion:*' select-prompt %SScrolling active: current selection at %p%s
zstyle ':completion:*' use-compctl false
zstyle ':completion:*' verbose true

zstyle ':completion:*:*:kill:*:processes' list-colors '=(#b) #([0-9]#)*=0=01;31'
zstyle ':completion:*:kill:*' command 'ps -u $USER -o pid,%cpu,tty,cputime,cmd'
plugins=(git)
source /usr/share/sudo-zsh/sudo.plugin.zsh

alias cat="/usr/bin/bat"
alias man="/usr/bin/tldr"
alias man1="/usr/bin/man"
alias vim="/usr/bin/nvim"
alias icat='kitty +kitten icat'
alias icat50='kitty +kitten icat --place 50x50@75x5'
alias icat25='kitty +kitten icat --place 25x25@75x5'
alias d="kitty +kitten diff"
#alias ls="logo-ls"
alias ls="lsd"
[ "$TERM" = "xterm-kitty" ] && alias ssh="kitty +kitten ssh"

#cambiar temas
eval "$(oh-my-posh init zsh --config ~/.poshthemes/montys.omp.json)"

[ -f ~/.fzf.zsh ] && source ~/.fzf.zsh
source /home/natsu/.zsh-syntax-highlighting/zsh-syntax-highlighting.zsh
source ~/.zsh/zsh-autosuggestions/zsh-autosuggestions.zsh
export _JAVA_AWT_WM_NONREPARENTING=1

#source /home/natsu/zsh-syntax-highlighting/zsh-syntax-highlighting.zsh

curl wttr.in
