#include <expand/expand.h>

char 	find_first_quote(const char *str)
{
	int 	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '\'')
			return (str[i]);
		else if (str[i] == '"')
			return (str[i]);
	}
	return (0);
}

void	expand_antislash(t_string *string, t_token_type type)
{
	int 	i;

	i = -1;
	while (string->s[++i])
	{
		if (string->s[i] == '\\' && string->s[i + 1] == '\\')
		{
				string_remove_char(string, i);
				i++;
		}
		if (type == E_TOKEN_WORD)
			if (string->s[i] == '\\' && string->s[i + 1] != '\\')
				string_remove_char(string, i);
	}
}

t_exp   *expand_remove_quote(t_exp *exp)
{
	char		*c;
	char 		quote;

	if (exp->type != E_TOKEN_SQUOTE)
		expand_antislash(exp->str, exp->type);
	if ((quote = find_first_quote(exp->str->s)) != 0)
		while ((c = ft_strchr(exp->str->s, quote)))
			string_remove_char(exp->str, c - exp->str->s);
	if (exp->type == E_TOKEN_SQUOTE || exp->type == E_TOKEN_DQUOTE)
		exp->type = E_TOKEN_WORD;
	return (exp);
}