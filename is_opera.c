int is_opera(char c)
{
	if (c == '&' || c == '>' || c == '<' || c == '|' || c == ';')
		return (1);
	return(0);
}
