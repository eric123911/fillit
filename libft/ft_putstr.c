/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 13:30:42 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 17:34:42 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


#include "libft.h"

void	ft_putstr(char const *s)
{
	if (!s)
		return ;
	write(1, s, ft_strlen(s));
}

#include <stdio.h>
#include <wchar.h>
#include <locale.h>

typedef unsigned char utf8_t;

#define isunicode(c) (((c)&0xc0)==0xc0)

int utf8_decode(const char *str,int *i) {
    const utf8_t *s = (const utf8_t *)str; // Use unsigned chars
    int u = *s,l = 1;
    if(isunicode(u)) {
        int a = (u&0x20)? ((u&0x10)? ((u&0x08)? ((u&0x04)? 6 : 5) : 4) : 3) : 2;
        if(a<6 || !(u&0x02)) {
            int b; //,p = 0;
            u = ((u<<(a+1))&0xff)>>(a+1);
            for(b=1; b<a; ++b)
                u = (u<<6)|(s[l++]&0x3f);
        }
    }
    if(i) *i += l;
    return u;
}


int	main(void) {
	char input[100] = "■";
	int i, l, z;
	for(i=0; i<20 && input[i]!='\0'; ) {
		if(!isunicode(input[i])) i++;
		else {
			l = 0;
			z = utf8_decode(&input[i],&l);
			printf("Unicode value at %d is U+%04X and it\'s %d bytes.\n",i,z,l);
			i += l;
		}
	}
	setlocale(LC_CTYPE, "UTF-8");
	//wchar_t try[] = {0xE2, 0x96, 0xA0};
	ft_putstr("\u25A0");
	/*for(x=0;x<3;x++)
        putwchar(try[x]);
		ft_putchar('\n');*/
	return 0;
}
