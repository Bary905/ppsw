unsigned char ucFindTokensInString (char *pcString);
enum KeywordCode {LD, ST, RST};
enum Result eStringToKeyword (char pcStr[],enum KeywordCode *peKeywordCode);
void DecodeTokens(void);
void DecodeMsg(char *pcString);
