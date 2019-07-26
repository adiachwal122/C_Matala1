#include <stdio.h>
#include <stdbool.h>

int check(int input []){
    
    for( int i = 0; i< 3; i++){
        while (input[i] < 1 ){
            printf("Invalid numbers ! Please Enter new numbers\n");
            scanf("%d%d%d" , &input[0], &input[1], &input[2]);
        }
        
    }
}

int* ArraySort(int input[]){
    
    int temp;
    
     for (int i = 0; i < 2; i++) {  // to sort the array
        if (input[i] > input[i+1]){
            temp = input[i+1];
            input[i+1] = input[i];
            input[i] = temp;
           
        }
        
    }
    
    if (input[0] > input[1]){  //incase the Array isnt sorted perfectlly 
        temp = input[1];
        input[1] = input[0];
        input[0] = temp;
    }
}


void main() {
    
    int X = 0, Y = 0, Z = 0;
    int ok = false; //in case the user entered wrong int
  
    printf("please enter 3 numbers with spaces\n");
    int input[3];
   
    while (!ok){
        scanf("%d%d%d" , &X, &Y, &Z);
        input [0] =X;
        input [1] =Y;
        input [2] =Z;
        ok = check(input);
   
    }
    
    ArraySort(input);
    
    printf("packet sizes are %d %d %d \n" , input[0], input[1], input[2]);


    int turn = 0; // the computers turn

    if((input[0] + input[1] == input[2] )|| (input[0] + input[2] == input[1] ) ||(input[2] + input[1] == input[0] )){
        turn = 1;
    }
    
    while((input[0] + input[1] + input[2]) != 0 ){   //continus as long as the player didnt lose

        if (turn == 0){
        
            ArraySort(input);
            
            if((input[0] == 0) && (input[1] == 0) && (input[2] > 1)){
                printf("I turned %d to 1 \nGame Over - You Lost !!",input[2]);
                input[2]=1;
                break;
			}
			
			else if((input[0] == 0) && (input[1] == 0) && (input[2] == 1)){
                printf("I turned %d to 0 \nGame Over - I Lost !!",input[2]);
                input[2]=0;
                break;
			}
			
			else if((input[0] == 0) && (input[1] == 1) && (input[2] >= 1)){
                printf("I turned %d to 0 \nGame Over - You Lost !!",input[2]);
                input[2]=0;
                break;
            }
            
            else if((input[0] == 1) && (input[1] == 1) && (input[2] > 1)){
                printf("I turned %d to 1 \n",input[2]);
                input[2]=1;
                turn=1;
            }
            
            else {
                int num = input[1] - input[0];
                printf("I turned %d to %d \n", input[2], num);
                input[2] = num;
                turn = 1;
            }
            
            ArraySort(input);
            
            printf("packet sizes are now: \n %d %d %d \n" , input[0], input[1], input[2]);
        
            turn = 1;
        }
    
    
        if (turn == 1){
        
            int num1, num2;
            ArraySort(input);
            
            printf("please state how much to take ?\n");
            scanf ("%d to %d", &num1,  &num2 );
        
            while (num2 >= num1 || num1 != input[0] && num1 != input[1] && num1 != input[2] || num2 < 0){
                printf("Against the ruls, Please enter new number ! \n");
                scanf("%d to %d", &num1,  &num2 );

            }
        
            if (num1 == input[0]){
                input[0] = num2;
                turn = 0;

            }
        
            else if (num1 == input[1]){
                input[1] = num2;
                turn = 0;

            } 
        
            else {
                input[2] = num2;
                turn = 0;

            }
        
        }

    }

}