 //Algorithm for revealing mine is as follows:
/*let A-->unfolded bomb position
     B-->unfolded empty position
     C--> revealed square with no neighboring bombs
     D-->revealed as bombs
     countneighborwithbombs-->counts number of neighbors with bombs to the  revealed one
     E-->revealed blank
     
     
     
     Enter x,y:
     board[x][y]
     if A==false
     		then
     		gameover==true
     		A=D
    
    if B
    		then
    		if countneighborswithBoard==0
    		 then 
    		 		if(checkBombs==false)//no bombs
    		 		
    		 		then B=E
    		 		
    		 				then board[x+1][y]=E
    		 				     board[x+1][y-1]=E
    		 				     board[x-1][y]=E
    		 				     board[x-1][y+1]=E
    		 				     board[x-1][y-1]=E
    		 				     board[x+1][y+1]=E
    		 				     board[x+1][y]=E
    		 				     do this step recursively
    		 				     
    		 				     
    	  if B
    	  			then
					  if countneighborwithbomb>=1
					   then
					      countneighborswithbombs++ //put the number of neighboring bombs in neighborwithbombs
					  		   
					   
			else
			   if board[x][y]==(A+B)
			     then
			       print("YOU WON!)
			       gameover==true
					    
  */	 

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

#define MAXMINES 10
#define MAXBOARDSIDE 25  
 

//int	getwidth(	int width) { 
//
//	return width;
//}
//
//int		getlength(	int length	){
//
//	return length;
//	
//}
//
//      
//int bombnumber(int l,int w) {
//	int bombs;
//	if(	getlength(l)&&getwidth( w )) {
//	bombs=10;
//	}
//	return bombs;
//}
	//takes in user's input
void userinput(int *x_axis,int *y_axis,int l,int w){ 

	 	
	 		printf("Enter your horizontal coordinates(0-9)\n");
	 		scanf("%d",x_axis);
	 		//confirming if input is a number
	 		if(isdigit(*x_axis)||*x_axis>l||*x_axis<0){
	 			
	 			while(isdigit(*x_axis)||*x_axis>l||*x_axis<0){
	 				printf("\nIncorrect\n\nEnter your horizontal coordinates(0-9)\n");
			    	scanf("%d",x_axis);
				 }
				
			      
			        }
	 				 	 
			 printf("\nEnter your vertical coordinates(0-9)\n");
	 		scanf("%d",y_axis);
	 			//confirming if input is a number
	 		if(isdigit(*y_axis)||*y_axis>w||*y_axis<0) {
	 			   while(isdigit(*y_axis)||*y_axis>w||*y_axis<0){
	 			   	printf("\nIncorrect\n\nEnter your vertical coordinates(0-9)\n");
					scanf("%d",y_axis);
					}
					
				    
			 }
	 }
	 
	 
	 void boardview(char visualBoard[][MAXBOARDSIDE],int l,int w){
	 
	 	int a,b;
	 	
		  	for(a=0;a< l;a++){
		  		 	for(b=0;b<w;b++){
		  		 		printf("%c \t",visualBoard[a][b]);
		  		 		system("color 3a");
					   }
					   printf("\n\n");
			  }
	 }
	 // a function that checks for bombs
	 bool checkBomb(char board[][MAXBOARDSIDE],int column,int row) {
	       
			if(board[row][column]=='#')//# is the bomb
		    	{   return true;
			   	}
			else 
			return false;
                                                                       	}
	 //counts number of neighboring mines using given coordinates
	int numberofneighborsbombs(char secretBoard[][MAXBOARDSIDE],int bombs[][2],int column,int row){
		int count=0;
	       //the below action tries to get the neighbor of the given coordinate
			if(checkBomb(secretBoard,column,row-1)!=false){count+=1;} //top
			
		     if(checkBomb(secretBoard,column+1,row)!=false){count+=1;} //right 
			                                            	                                                 
		     if(checkBomb(secretBoard,column+1,row-1)!=false){count+=1;}//top-right
			                                               
			if(checkBomb(secretBoard,column,row+1)!=false){count+=1;}//bottom   
			                                              
			if(checkBomb(secretBoard,column-1,row)!=false){count+=1;}//left    
			                                        	
	      	if(checkBomb(secretBoard,column+1,row+1)!=false){count+=1;}//bottom-right
			                                                	
			if(checkBomb(secretBoard,column-1,row-1)!=false){count+=1;}//top-left
			
			if(checkBomb(secretBoard,column-1,row+1)!=false){count+=1;}//bottom-left	                                                     	                                     
			return count;
	}
	//the function below gives the game status so incase of bomb coordinate input  the game is over
	bool  teardown(int column,int row,int *stepsRemaining,char visualBoard[][MAXBOARDSIDE],int bombs[][2],char secretBoard[][MAXBOARDSIDE],	int l,int w,int b)
	{  
	   	if(visualBoard[row][column]!='-'){ return false;}// '-' unrevealed coordinate representation                         	
		//secretBoard contains bomb coordinates	 while visualBoard will be the board the user will see
	     int a;

		if (secretBoard[row][column]=='#')
		{
					visualBoard[row][column]=='#';
					for(a=0;a<b;a++){
							visualBoard[bombs[a][0]][bombs[a][1]]='#';
										//this reveals that you opened a bomb position hence gameover will be true
							printf("Boom!Destroying the game\n");//this prints out only 
							exit(0);										//when the user input matches a bomb and flag is a  or A
																	
							return true;
							exit(0);//the game ends when secretbomb and visualbomb have all '#' that is the bomb	
		               	}
			  }
			   else
              {       int count=0;
	         count=numberofneighborsbombs(secretBoard,bombs,column,row); 
             (*stepsRemaining)--; 
        visualBoard[row][column] = count + '0'; 
       if (!count) 
        {       //coordinates are the same as in  numberofneighborsbombs
               //below codes is used to recursively reveal empty cells
                  if ( checkBomb(secretBoard,column,row-1)!=true){
				         teardown(column,row-1,stepsRemaining,visualBoard,bombs,secretBoard,l,w,b);
				                                                  } 				
                   if (checkBomb(secretBoard,column+1,row+1)!=true) 	{
				      	teardown(column+1,row+1,stepsRemaining,visualBoard,bombs,secretBoard,l,w,b);
												                         	}
				   if (checkBomb(secretBoard,column-1,row) !=true) 	{
					teardown(column-1,row,stepsRemaining,visualBoard,bombs,secretBoard,l,w,b);
				 						  } 
				    if (checkBomb(secretBoard,column+1,row+1)!=true) {
				   teardown(column+1, row+1, stepsRemaining,visualBoard,bombs,secretBoard,l,w,b);
							                                       	}
                 if (checkBomb(secretBoard,column+1,row-1)!=true) {
				    	teardown(column+1,row-1,stepsRemaining,visualBoard,bombs,secretBoard,l,w,b);
								                                 	}
					 if (checkBomb(secretBoard,column+1,row)!=true) {
				  	teardown(column+1,row,stepsRemaining,visualBoard,bombs,secretBoard,l,w,b);
													 }  
               if (checkBomb(secretBoard,column-1,row-1)!=true) 	{
				  	teardown(column-1,row-1,stepsRemaining,visualBoard,bombs,secretBoard,l,w,b); 
				 													 }
				 if (checkBomb(secretBoard,column,row+1)!=true)		{
				   	teardown(column,row+1,stepsRemaining,visualBoard,bombs,secretBoard,l,w,b);
											                     	}   
						}
						else{
							printf("error");
						}

	}	
	}
	
	
//puts mines on the board and randomly generates them
	 void  putMineOnBoard(char secretBoard[][MAXBOARDSIDE],int bombs[][2],int l,int w,int b)
	 {
			     	bool mark[MAXBOARDSIDE*MAXBOARDSIDE];
			    	memset(mark,false,sizeof(mark));//returns a pointer of mark
			         int i=0,a;
			    
					       for(i=0;i<b;)   
						    {
					       	   int boardarea=l*w;
						  	    int scatteredvar=rand()%boardarea;//initialization of random bombs value
						  	    int y_axis=scatteredvar%w;//bombs on y axis
						     	int x_axis=scatteredvar/l;//bombs on x axis
						    
					  	     if(mark[scatteredvar]!=true){
					  	    bombs[i][1]=y_axis; 
					  		bombs[i][0]=x_axis;
					  				
					  	  secretBoard[bombs[i][0]][bombs[i][1]] = '#'; //# represents the bombs
					  		mark[scatteredvar]!=false;
					  		i++;
		                                            }
	                        }
	    }
	// A Function to initialise the game 
	void initialiseGame(char secretBoard[][MAXBOARDSIDE], char visualBoard[][MAXBOARDSIDE],int l,int w) 	{ 
	    //srand(time(NULL));// makes use of players computer internal clock to control 
							//the choice of the random bombs generated
	    int b,a;

	    
	   //makes the visualboard &secretBoard to have no mines
	    for ( a=0; a<l; a++) 
	    { 
	        for ( b=0; b<w; b++) 
	                  { 
	            			visualBoard[a][b] = secretBoard[a][b] = '-'; //making the board visible and empty at the first instance
	                   } 
	    } return;
                	} 
	//replacesMine finds empty coordinates   from the given position then puts mine in them 
	void replaceMine (char board[][MAXBOARDSIDE], int column,int row ,int l,int w) { 
	int a,b;

	
	    for ( a=0; a<l; a++) 
	     { 
	        for ( b=0; b<w; b++) 
	             {  
	                if (board[a][b] != '#') 
	                   { board[a][b] = '#'; 
	                    board[row][column] = '-'; 
	                    return; 
	                    } 
	             } 
	     } 	} 
	//method to play game	
	void gameplayer(int l,int w,int	 b	)
	{
		
		int x_axis,y_axis,bombs[MAXMINES][2];
		
		char visualBoard[MAXBOARDSIDE][MAXBOARDSIDE],flagtype,secretBoard[MAXBOARDSIDE][MAXBOARDSIDE];
		
		bool  gameover=false;
		

 		int stepsRemaining = (l*w) - ( b);
 		
	    initialiseGame(visualBoard,secretBoard,	 l, w);
	    
		putMineOnBoard(secretBoard,bombs, l, w,b);
	    
		int positionstate=0;
		
		while(gameover!=true)
		{
			boardview(visualBoard,l,w);
			printf("(F) Flag the spot as a mine,(R) remove a flag ,(A) Assert that a spot is mine free,(Q)Quit\n");
			scanf("%c",&flagtype);
		   if(flagtype=='Q'||flagtype=='q')
		     {
		  		 exit(0);
		     }
		   else if(flagtype=='A'||flagtype=='a'||flagtype=='r'||flagtype=='R'||flagtype=='f'||flagtype=='F')
		   {
		   
		        	userinput(&x_axis,&y_axis,l,w);
			    	if(positionstate==0)
					 {
					
				    	if(checkBomb(secretBoard,y_axis,x_axis)!=false)  
						{
						    replaceMine(secretBoard,y_axis,x_axis,l,w);
				                
			           	}
	                            
					}
				positionstate++;//increases the current your position point
				gameover=teardown(y_axis,x_axis,&stepsRemaining,visualBoard,bombs,secretBoard, l, w,b);  
		 if((gameover==false&&flagtype=='A')||(gameover==false&&flagtype=='a'))//Assertion
	         	{
					printf("OK!\n");
					scanf("%c",&flagtype);
					gameover=teardown(y_axis,x_axis,&stepsRemaining,visualBoard,bombs,secretBoard, l, w,b);
		        }
		else if((gameover==false&&flagtype=='F')||(gameover==false&&flagtype=='f'))//puts a flag
			 {		scanf("%c",&flagtype);
				    visualBoard[x_axis][y_axis]='f';
					gameover=teardown(y_axis,x_axis,&stepsRemaining,visualBoard,bombs,secretBoard, l, w,b	); 
		  }
		  else if((gameover==false&&flagtype=='r')||(gameover==false&&flagtype=='R'))//removes the flag
			 {		scanf("%c",&flagtype);
				    visualBoard[x_axis][y_axis]='-';
					gameover=teardown(y_axis,x_axis,&stepsRemaining,visualBoard,bombs,secretBoard, l, w,b);
					visualBoard[x_axis][y_axis]='-'; 
		    }
		}
//		else{
//	   	
//			gameplayer(l,w,b);
//		   }
		 
	   	}


	} 
	


	int main(int argc,char *argv[]) 
	{  	
//        int L=atoi(agrv[1]);
//        int W=atoi(agrv[2]);
        int l,w,b;
	   scanf("%d",&l);
	   scanf("%d",&w);
	   b=10;
	
       	gameplayer(l, w,b);
	}

