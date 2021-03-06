cmake_minimum_required(VERSION 3.0)
project(42sh)

set(CMAKE_CXX_STANDARD 11)
set (CMAKE_C_FLAGS "-g -Wall -Werror -Wextra")

set(SOURCE_FILES
		srcs/autocomplete/autocomplete.c
        srcs/autocomplete/autocomplete_get_bin.c
		srcs/autocomplete/autocomplete_get_path.c
		srcs/autocomplete/autocomplete_get_words.c
		srcs/autocomplete/autocomplete_is.c
		srcs/autocomplete/autocomplete_utils.c
		srcs/autocomplete/autocomplete_sort.c

		srcs/automaton/automaton.c

		srcs/ast/ast_cmp.c
		srcs/ast/ast_utils.c
		srcs/ast/ast_built.c
		srcs/ast/ast_is_redir.c
		srcs/ast/ast.c
		srcs/ast/ast_built_wr.c

		srcs/btree/btree_create_node.c
		srcs/btree/btree_print.c
		srcs/btree/btree_apply.c
		srcs/btree/btree_utils.c

		srcs/builtins/builtin_local_var.c
		srcs/builtins/builtin_utils.c
		srcs/builtins/builtin_utils2.c
		srcs/builtins/builtin_chdir.c
		srcs/builtins/builtin_chdir_expand.c
		srcs/builtins/builtin_echo.c
		srcs/builtins/builtin_exit.c
		srcs/builtins/builtin_help.c
		srcs/builtins/builtin_help_2.c
		srcs/builtins/builtin_pwd.c
		srcs/builtins/builtin_environ.c
		srcs/builtins/builtin_environ_env.c
		srcs/builtins/builtin_environ_env_exec.c
		srcs/builtins/builtin_environ_env_i.c
		srcs/builtins/builtin_environ_env_u.c
		srcs/builtins/builtin_history.c
		srcs/builtins/builtin_history_acdws.c
		srcs/builtins/builtin_history_print.c
		srcs/builtins/builtin_history_npr.c
		srcs/builtins/builtin_local_var.c
		srcs/builtins/builtin_help_3.c
		srcs/builtins/builtin_help_4.c
		srcs/builtins/builtin_chdir_abs.c

		srcs/core/input_get.c
		srcs/core/sh_option.c
		srcs/core/sh_loop.c
		srcs/core/sh_get_input.c
		srcs/core/init.c
		srcs/core/deinit.c
		srcs/core/input.c
		srcs/core/input_utils.c
		srcs/core/input_utils_2.c
		srcs/core/main.c
		srcs/core/usage_help.c
		srcs/core/prompt.c
		srcs/core/input_windows.c
		srcs/core/input_draw.c
		srcs/core/input_move.c

		srcs/environ/env_list_utils.c
		srcs/environ/environ.c
		srcs/environ/getter_env.c
		srcs/environ/env_utils.c
		srcs/environ/modif_env.c

		srcs/exec/sh_heredoc_input.c
		srcs/exec/check_path.c
		srcs/exec/sh_process_exec.c
		srcs/exec/sh_exec.c
		srcs/exec/sh_exec_pipe.c
		srcs/exec/sh_exec_redir.c
		srcs/exec/sh_heradoc.c
		srcs/exec/exec_tlist.c
		srcs/exec/sh_exec_list_fd.c
		srcs/exec/sh_exec_redir2.c
		srcs/exec/sh_exec_redir3.c
		srcs/exec/sh_exec_local_var.c
		srcs/exec/sh_fork.c
		srcs/exec/sh_pipe.c
		srcs/exec/sh_open.c
		srcs/exec/sh_exec_builtin.c
		srcs/exec/sh_exec_backup_fd.c

		srcs/expand/expand.c
		srcs/expand/expand_dol.c
		srcs/expand/expand_history.c
		srcs/expand/expand_history_tools.c
		srcs/expand/expand_merge.c
		srcs/expand/expand_print.c
		srcs/expand/expand_quote.c
		srcs/expand/expand_utils.c
		srcs/expand/ft_replace.c
		srcs/expand/expand_history_replace.c

		srcs/secure_memory/ft_secu_free.c
		srcs/secure_memory/ft_secu_malloc.c

		srcs/select/select.c
		srcs/select/select_data.c
		srcs/select/select_display.c
		srcs/select/select_display_init.c
		srcs/select/select_display_utils.c
		srcs/select/select_exit.c
		srcs/select/select_init.c
		srcs/select/select_list_utils.c
		srcs/select/select_list_utils_2.c

        srcs/history/history_init.c
		srcs/history/history.c
		srcs/history/history_list_utils.c
		srcs/history/history_getter.c
		srcs/history/history_getter_2.c
		srcs/history/history_print.c
		srcs/history/history_arrow.c
		srcs/history/history_research.c
		srcs/history/history_research_start_end.c
		srcs/history/history_input_utils.c

		srcs/lexer/lexer_init.c
		srcs/lexer/lexer.c
		srcs/lexer/lexer_clean.c
		srcs/lexer/lexer_utils.c


		srcs/parser/parser.c

		srcs/signals/get_pid_childs.c
		srcs/signals/signals.c
		srcs/signals/signals_handler.c

		srcs/tcaps/tcaps_exec_alt_c.c
		srcs/tcaps/tcaps_exec_alt_v.c
		srcs/tcaps/tcaps_exec_alt_arrows.c
		srcs/tcaps/tcaps_exec_arrow.c
		srcs/tcaps/tcaps_exec_arrow_normal.c
		srcs/tcaps/tcaps_exec_arrow_select.c
		srcs/tcaps/tcaps_exec_backspace.c
		srcs/tcaps/tcaps_exec_ctrl_1.c
		srcs/tcaps/tcaps_exec_ctrl_select.c
		srcs/tcaps/tcaps_exec_ctrl_2.c
		srcs/tcaps/tcaps_exec_delete.c
		srcs/tcaps/tcaps_exec_end_home.c
		srcs/tcaps/tcaps_exec_insert.c
		srcs/tcaps/tcaps_exec_tab.c
		srcs/tcaps/tcaps_exec_escape.c
		srcs/tcaps/tcaps_key_exec.c
		srcs/tcaps/tcaps_redraw_line.c
		srcs/tcaps/tcaps_exec_escape_enter.c
		srcs/tcaps/tcaps_exec_init.c
		srcs/tcaps/tcaps_exec_alt_input.c

		srcs/term/term_modes.c

		srcs/tools/ft_isdigit_str.c
		srcs/tools/sh_test_access.c
		srcs/tools/is.c
		srcs/tools/getpwd.c
		srcs/tools/sh_ret.c
		srcs/tools/array_free_elem.c
		srcs/tools/is_printstr.c
		srcs/tools/print_verb.c
		srcs/tools/sh_exit_error.c

		srcs/tests/lexer_tests.c
		srcs/tests/env_tests.c
		srcs/tests/parser_tests.c
		srcs/tests/env_tests.c
		srcs/tests/expand_tests.c
		srcs/tests/ast_tests.c
		srcs/tests/exec_tests.c
		srcs/tests/local_var_tests.c)

include_directories(includes)

#Libcbc
add_subdirectory(libcbc)
include_directories(libcbc/libft/includes libcbc/libftprintf/includes libcbc/liblogger/includes libcbc/libtcaps/includes)

add_executable(42sh ${SOURCE_FILES})

target_link_libraries(42sh cbc curses)
