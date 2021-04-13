function! TerminalWrapper(command)
  exec 'new'
  if exists('g:split_term_size')
    exec 'resize ' . g:split_term_size
  endif
  exec 'term ' . a:command
  exec 'setlocal noru nonu'
  exec 'startinsert'
endfunction

let mapleader = " "
let g:split_term_size = 10

command! -nargs=0 CompileAndRun write | call TerminalWrapper(printf('g++ -std=c++17 -O2 -Wall -o %s.out %s && %s.out', expand('%:r'), expand('%'), expand('%:r')))

if has("autocmd")
  autocmd FileType cpp nnoremap <leader>fw :CompileAndRun<CR>
  augroup templates
    autocmd BufNewFile *.cpp 0r templates/basic.cpp
  augroup END
endif
