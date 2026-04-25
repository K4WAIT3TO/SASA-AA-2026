#include <stdio.h>
int main(){
	unsigned int SM, SE, SAM, SAE, AM, AE, RM;
	scanf("%u%u%u%u%u%u%u", &SM, &SE, &SAM, &SAE, &AM, &AE, &RM);
	int K, N;
	scanf("%d%d", &K, &N);
	unsigned int all=(K==32)?0xFFFFFFFFu:(1u<<K)-1;
	unsigned int closed=all, synsent=0, synrcvd=0, estab=0, reset=0;
	
	for(int j=0;j<N;j++){
		unsigned int P, flag, t;
		scanf("%u%u", &P, &flag);
		unsigned int recv=P&all&~reset;
		if(flag&RM){
			closed&=~recv;synsent&=~recv;
			synrcvd&=~recv;estab&=~recv;
			continue;
		}
		
		if((flag&AM)==AE){t=synrcvd&recv;estab|=t;synrcvd&=~t;}
		if((flag&SAM)==SAE){t=synsent&recv;synrcvd|=t;synsent&=~t;}
		if((flag&SM)==SE){t=closed&recv;synsent|=t;closed&=~t;}
	}
		
	int found=0;
	for(int i=0;i<K;i++){
		if(estab>>i&1){printf("%d\n", i);found=i;}
	}
	if(!found)printf("NONE\n");
}
