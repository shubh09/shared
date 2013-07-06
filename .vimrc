set nocompatible               " be iMproved
filetype off                   " required!
 
set rtp+=~/.vim/bundle/vundle/
call vundle#rc()
   
" let Vundle manage Vundle
" required!
Bundle 'gmarik/vundle'
Bundle 'Valloric/YouCompleteMe'

filetype plugin indent on     

set number
syntax on
"set autoindent
set backspace=indent,eol,start

inoremap {	{}<Left>
inoremap {<CR>	{<CR><CR>}<Up><Tab>
inoremap {}	{}

inoremap "	""<Left>
inoremap ""	""

inoremap (	()<Left>
inoremap ()	()

set smartcase
set clipboard=unnamedplus

