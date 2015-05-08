main(){int r,x,y;scanf("%x,%d,%d",&r,&x,&y);
r=r&~(1<<x)&~(1<<y-2)|(3<<y-1);printf("%x\n",r);}
