

main(){
	
	int num,res;
	
    printf("Insert number: ");
    scanf("%d",&num);
    
    while(num!=0){
    	
    	res+=num%10;//res=res+num%10
    	num/=10; //num=num/10
    	
	}

    printf("That's the result: ""%d",res);
}

