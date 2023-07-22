#include<reg51.h>
void main()
{
unsigned char
i=0;
P0 = 0X00;
while(1)
{
for(i=0;i<0xff;i++)
{
P0=i;
}
}
}
