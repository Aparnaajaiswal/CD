%{
    int count=0;
%}

%%
[A-Z]{printf("%s Capital letter",yytext); count++;}
.* {printf("%s not a capital letter", yytext);}
%%

void main(){
    yylex();
    printf("total capital letters: %d", count);
}
int yywrap(){}



%{
    include <std.io>
%}

%%
[0-9]+ {printf("integer %s", yytext);}
[0-9]*.[0-9]+{printf("float %s",yytext);}
[a-zA-Z_][A-Za-z0-9_]* {printf("identifier: %s",yytext);}
"+"|"-"|"/"|"*" {printf("operators %s",yytext);}
[\n\t]+ /*ignore*/
. {printf("unknown",yytext);}
%%

int yywrap(){}
void main(){
     yylex();
     return 0;
}
