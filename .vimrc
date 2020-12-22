syntax on
set number " line number
set cursorline " show line cursor
set shiftwidth=4
set softtabstop=4
set tabstop=4
set expandtab " change tab to blank
set autoindent
set smartindent
set cindent
set showmatch " show match braces
set matchtime=3 " time for vim to wait for showmatch
set ruler

nnoremap <F4> :w <CR> :!g++ % -o %< --std=c++14 -Wall -Wshadow -g -fsanitize=address -fsanitize=undefined && for i in ./in*; do echo $i; ./%< < $i; done <CR>
