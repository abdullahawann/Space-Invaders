#include <iostream>
#include <fstream>
#include <string>
#include "mygraphics.h"
#include "myconsole.h"
using namespace std;

void storeScore(int score)                                            // This will save the score of the game.
{
	fstream file;
	file.open("score.txt",ios::out | ios::app);
	file << score << endl;
	file.close();
}

void displaymax(int score2[])                                        // This will display the highest 10 scores of the game.
{
	int i=0, j=0, min=0, desc, count=0, count2=1;
	fstream file;
	file.open ("score.txt", ios::in);

	while (!file.eof())
	{
		file >> min;
		score2[i] = min; 
		i++;
		count++;
	}
	file.close();

	for (i=0; i<count; i++)                                //  This is used to sort highest score in descending order.
	{
        for (j=i+1; j<count; j++)
        {
            if (score2[i] < score2[j])
            {
                desc = score2[i];
                score2[i] = score2[j];
                score2[j] = desc;
            }
        }
    }

	if (count == 0)
	{
		cout << "No highest score yet.";
	}
	else 
	{
		cout << "Top 10 Highest scores are : ";
		cout << endl << endl;

        for (i=0; i<10; i++)
        {
		    cout << "Highest score # " << count2 << " : ";
            cout << score2[i] << endl;
			count2++;
        }
	}
}
int main()
{
	int lvl;
    char Space_Invaders[] = "Space Invaders";
	SetWindowTitle(Space_Invaders);

cout << endl;
cout << "Welcome Hero to this wild unknown where once peace was a norm but then these unknown creatures started barging around " << endl << "this GALAXY. Are you ready for this challenge to fight against these enemies ? " << endl << endl << endl;
cout << "RULES :" << endl << endl;
cout << "1. Aliens are coming down from upward gradually. You have to use your gun to fire the bullet by pressing 'SPACE BAR' to" << endl << "   kill the Aliens." <<endl << "2. Kill all the ALiens before they reach the Border at the bottom. " << endl << "3. You can move your spaceship Left(<-), Right(->), Up(^) and Down (|) by using arrow keys. " << endl << "4. Don't let Aliens hit your spaceship because with every hit you will lose 1 life be careful you only have 3." << endl << "5. Shhh !!! we have hidden some secret spells in your keyboard find them and this mission might just become easier." <<endl << "6. Press 'P' or 'ESC' to pause the game or to exit the game." << endl << "7. Press 'S' to save and 'L' to load the saved game." << endl << "8. Game will be a bit difficult at every level." << endl << endl << "\t\t\t\t\t\t GOOD LUCK SOLDIER !!! " << endl << endl << endl;
cout << "Choose difficulty level 1.Easy 2.Medium 3.Hard  (1/2/3) : ";
cin >> lvl;

if (lvl == 1){                       // Easy level.
	string sg;
	bool play=true;
	bool flag2=true;
	bool flag3=true;
	int life1=3;
	int score1=0;
	int score2[500];  

while(play)         // This is the first loop from where the initialization and game start.
{
	int i,q,k;
	int enemy=55;
    int win_x, win_y;
	int move,dead;
	float box_x1[100] = {245};
	float box_y1[100] = {20};
	float box_x2[100] = {};
	float box_y2[100] = {}; 
	int ene[100] = {};
	bool bullet=false, win=true,lose=true , flag=true, pressed = false;
	char life[]="Life : ";
	char score[]="score :";char vic[]="You Won !!! Play Again ? (Y/N) : "; char loss[]="You lost !!! TRY AGAIN ? (Y/N):";
	char exit[]="Game Paused !!! Do you want to Exit the game ? (Y/N) : ";
	char lives[] = "All Lives used !!! Do you want to try again (Y/N) ???";
	char choice;
	int bx=1000, by=1000;
	char Space_Invaders[] = "Space Invaders";
	float box_x;
	float box_y; 
	int ball_x;
	int ball_y;
	int ball_x1;
	int ball_y1;
	int ball_x2;
	int ball_y2;
	float b=0.5;
	GetWindowDimensions(win_x, win_y);
    box_x = win_x / 2;                                                  // This block controls the location of spaceship.
    box_y = win_y - 20;

	    for (move=1; move<=11; move++)
		{
			box_x1[move] = box_x1[move - 1] + 45;
		}
		for (move=0; move<11; move++)
		{
			box_x2[move] = box_x1[move] + 20;                              // This block contols the size of alliens.
		}
		for (move=1; move<=5; move++)
		{
			box_y1[move] = box_y1[move - 1] + 40;
		}
		for (move=0; move<5; move++)
		{
			box_y2[move] = box_y1[move] + 20;
		}
		for (move=0; move<=55; move++)
		{
			ene[move] = true;
		}
       system("cls");

   while (win && lose)                                                   // This is the second loop where all the event happens. 
		{
	        ball_x = (win_x / 2) + 436;
            ball_y = (win_y / 2) - 222;                                  // This draws the life. 
	        ball_x1 = (win_x / 2) + 450;
            ball_y1 = (win_y / 2) - 222;
            ball_x2 = (win_x / 2) + 464;
            ball_y2 = (win_y / 2) - 222;

			PlaceCursor(8,1);
			myLine(0, 5, win_x, 5, RGB(255,255,0));
		    myLine(win_x, 5, win_x, win_y, RGB(255,255,0));                  // These lines draw the borders.
		    myLine(0, win_y, win_x, win_y, RGB(255,255,0));
		    myLine(0, 5, 0, win_y, RGB(255,255,0));
			SetWindowTitle(Space_Invaders);
	        myDrawTextWithFont(win_x / 60, win_y / 35, 20, score, RGB(255, 255, 255), RGB(20, 20, 20));    
	        myDrawTextWithFont((win_x / 2) + 395, (win_y / 2) - 225, 20, life, RGB(255, 255, 255), RGB(20, 20, 20));   // This draw the text.    
			myEllipse(ball_x, ball_y, ball_x + 10, ball_y + 15, RGB(255, 0, 0), RGB(255, 0, 0));
			myEllipse(ball_x1, ball_y1, ball_x1 + 10, ball_y1 + 15, RGB(255, 0, 0), RGB(255, 0, 0));
			myEllipse(ball_x2, ball_y2, ball_x2 + 10, ball_y2 + 15, RGB(255, 0, 0), RGB(255, 0, 0));						   
		 
			if (life1 == 2)
			{
					myEllipse(ball_x2, ball_y2, ball_x2 + 10, ball_y2 + 15, RGB(12, 12, 12), RGB(12, 12, 12));
			}
			if (life1 == 1)
			{
				myEllipse(ball_x2, ball_y2, ball_x2 + 10, ball_y2 + 15, RGB(12, 12, 12), RGB(12, 12, 12));
			    myEllipse(ball_x1, ball_y1, ball_x1 + 10, ball_y1 + 15, RGB(12, 12, 12), RGB(12, 12, 12));
			}
			if (life1 == 0)
			{
				myEllipse(ball_x, ball_y, ball_x + 10, ball_y + 15, RGB(12, 12, 12), RGB(12, 12, 12));
				myEllipse(ball_x2, ball_y2, ball_x2 + 10, ball_y2 + 15, RGB(12, 12, 12), RGB(12, 12, 12));
			    myEllipse(ball_x1, ball_y1, ball_x1 + 10, ball_y1 + 15, RGB(12, 12, 12), RGB(12, 12, 12));
			}
			for (i=0; i<11; i++)                                // This block will clear previously drawn aliens.
			   {
					myRect (box_x1[i], box_y1[0], box_x2[i], box_y2[0], RGB(12, 12, 12), RGB(12, 12, 12));
					myRect (box_x1[i], box_y1[1], box_x2[i], box_y2[1], RGB(12, 12, 12), RGB(12, 12, 12));
					myRect (box_x1[i], box_y1[2], box_x2[i], box_y2[2], RGB(12, 12, 12), RGB(12, 12, 12));
					myRect (box_x1[i], box_y1[3], box_x2[i], box_y2[3], RGB(12, 12, 12), RGB(12, 12, 12));
					myRect (box_x1[i], box_y1[4], box_x2[i], box_y2[4], RGB(12, 12, 12), RGB(12, 12, 12));
		       }

			for (move=0; move<5; move++)                                // This controls the movement of aliens downwards.
				{
					  if(box_y1[move] < 480 && box_y2[move] < 480)
					  {
				    	box_y1[move] += 0.1;
					    box_y2[move] += 0.1;
					  }
					else
					{
						win=false;
						break;
					}
				}

			for (move=0; move<11; move++)                                     // This controls the movement of aliens side by side.
				{
					if (box_x1[move] < 100 || box_x1[move] > win_x-100)
						b = b*(-1);
					box_x1[move] += b;
					box_x2[move] += b;
				}
		
				for (i=0; i<11; i++)                                        // This block draws all enemies
				    {
					    if (ene[i] == true)
						    myRect (box_x1[i], box_y1[0], box_x2[i], box_y2[0], RGB(0, 153, 0), RGB(0, 255, 0));
					    if (ene[i + 11] == true)
						    myRect (box_x1[i], box_y1[1], box_x2[i], box_y2[1], RGB(0, 153, 0), RGB(0, 255, 0));
					    if (ene[i + 22] == true)
						    myRect (box_x1[i], box_y1[2], box_x2[i], box_y2[2], RGB(0, 153, 0), RGB(0, 255, 0));
				    	if (ene[i + 33] == true)
						    myRect (box_x1[i], box_y1[3], box_x2[i], box_y2[3], RGB(0, 153, 0), RGB(0, 255, 0));
					    if (ene[i + 44] == true)
						    myRect (box_x1[i], box_y1[4], box_x2[i], box_y2[4], RGB(0, 153, 0), RGB(0, 255, 0));
				    }
		
						myRect (box_x - 30, box_y, box_x + 20, box_y + 8, RGB(224, 224, 224), RGB(224, 224, 224));    // This draws the Spaceship.
						myRect (box_x - 10, box_y - 5, box_x, box_y, RGB(224, 224, 224), RGB(224, 224, 224));	
						myEllipse (box_x - 30 , box_y + 20 , box_x - 40, box_y - 10, RGB(192, 192, 192), RGB(224, 224, 224));	
						myEllipse (box_x + 20 , box_y + 20 , box_x + 30, box_y - 10, RGB(192, 192, 192), RGB(224, 224, 224));	
						int ch = CheckKeyPressed();                   // This block controls the movement of spaceship and also make spaceship move in borders;
                           if (ch == LEFTKEY)
						   {
					            myRect (box_x - 30, box_y, box_x + 20, box_y + 8, RGB(12,12,12), RGB(12,12,12)); 
						        myRect (box_x - 10, box_y - 5, box_x, box_y, RGB(12,12,12), RGB(12,12,12));	                    // This removes the prints drawn by the Spaceship.
						        myEllipse (box_x-30 , box_y+20 , box_x-40, box_y-10, RGB(12,12,12), RGB(12,12,12));	
						        myEllipse (box_x+20 , box_y+20 , box_x+30, box_y-10, RGB(12,12,12), RGB(12,12,12)); 	  
						   if(box_x > 20)
							    box_x -= 20;
						   }
                           else if (ch == RIGHTKEY)
						   {
						        myRect (box_x - 30, box_y, box_x + 20, box_y + 8, RGB(12,12,12), RGB(12,12,12)); 
						        myRect (box_x - 10, box_y - 5, box_x, box_y, RGB(12,12,12), RGB(12,12,12));	
						        myEllipse (box_x-30 , box_y+20 , box_x-40, box_y-10, RGB(12,12,12), RGB(12,12,12));	
						        myEllipse (box_x+20 , box_y+20 , box_x+30, box_y-10, RGB(12,12,12), RGB(12,12,12));
						   if(box_x < 940)
                                box_x += 20;
						   }
		                   else if (ch == UPKEY)
						   {
							    myRect (box_x - 30, box_y, box_x + 20, box_y + 8, RGB(12,12,12), RGB(12,12,12));
						        myRect (box_x - 10, box_y - 5, box_x, box_y, RGB(12,12,12), RGB(12,12,12));	
						        myEllipse (box_x-30 , box_y+20 , box_x-40, box_y-10, RGB(12,12,12), RGB(12,12,12));	
						        myEllipse (box_x+20 , box_y+20 , box_x+30, box_y-10, RGB(12,12,12), RGB(12,12,12));
						   if(box_y > 20)
							    box_y -= 15; 
						   }
		                   else if (ch == DOWNKEY)
						   {
					            myRect (box_x - 30, box_y, box_x + 20, box_y + 8, RGB(12,12,12), RGB(12,12,12));           
						        myRect (box_x - 10, box_y - 5, box_x, box_y, RGB(12,12,12), RGB(12,12,12));	
						        myEllipse (box_x-30 , box_y+20 , box_x-40, box_y-10, RGB(12,12,12), RGB(12,12,12));	
						        myEllipse (box_x+20 , box_y+20 , box_x+30, box_y-10, RGB(12,12,12), RGB(12,12,12));
						   if(box_y < 450)
			                    box_y += 15;
						   }
						   else if(ch == 83)
						   {
							   fstream myfile("savedgame.txt");
							   if(myfile)
							   {
								   myfile<<i<<endl<<q<<endl<<k<<endl<<play<<endl<<flag2<<endl<<flag3<<endl<<life1<<endl<<score1<<endl<<enemy<<endl<<win_x<<endl<<win_y<<endl<<move<<endl<<dead<<endl<<box_x1[move]<<endl<<box_y1[move]<<endl<<box_x2[move]<<endl<<box_y2[move]<<endl<<ene[i]<<endl<<bullet<<endl<<win<<endl<<lose<<endl<<flag<<endl<<pressed<<endl<<bx<<endl<<by<<endl<<box_x<<endl<<box_y<<endl<<b;
								   myfile.close();
							   }
						   }
						   else if(ch == 76)
						   {
							   fstream myfile("savedgame.txt");
							   myfile>>i;
							   myfile>>q;
							   myfile>>k;
							   myfile>>play;
							   myfile>>flag2;
							   myfile>>flag3;
							   myfile>>life1;
							   myfile>>score1;
							   myfile>>enemy;
							   myfile>>win_x;
							   myfile>>win_y;
							   myfile>>move;
							   myfile>>dead;
							   myfile>>box_x1[move];
							   myfile>>box_y1[move];
							   myfile>>box_x2[move];
							   myfile>>box_y2[move];
							   myfile>>ene[i];
							   myfile>>bullet;
							   myfile>>win;
							   myfile>>lose;
							   myfile>>flag;
							   myfile>>pressed;
							   myfile>>bx;
							   myfile>>by;
							   myfile>>box_x;
							   myfile>>box_y;
							   myfile>>b;
							   ClearScreen();
							   myfile.close();
						   }
						   else if (ch == 73)
						   {
							   b=0;
						   }
						   else if (ch == 79)                              // Cheats to change the movement of alliens side by side.
						   {
							   b=0.5;
						   }
						   else if (ch == 85)
						   {
							   b=1;
						   }
						   else if (ch == 27 || ch == 80)
						   {
							   win=false;
							   lose=false;
							   	if (win == false && lose == false)
		                        {
									  PlaceCursor(90,13);
			                          myDrawText (335, 222, 150, exit, RGB(255, 255, 255), RGB(0,0,0));
			                          cin >> choice;
			                          if (choice == 'y')
									  {
			                               play=false;
									       flag3=false;                                     // This block is to exit the game ot to pause the game.
										   break;
									  }
			                          else
				                           if (choice == 'n')
										   {
				                                 play=true;
									             flag3=true;
												 win=true;
												 lose=true;
												 ClearScreen();
										   } 
		                        }
						   }
						    
			   for (k = 0; k < 10; k++)                               // This loop will control the movement of bullet
			         {	                                         
				         if (bullet) 						
				             {
					            by -= 2;                                     // This controls the movement of bullet

				                for (dead = 0; dead < 11; dead++)
					                {
						               if (bx >= box_x1[dead] && bx <= box_x2[dead])
						                  {                                                                   //Checks for collision b/w any enemy and player bullet and eliminates enemy if any.
							           if (by >= box_y1[4] && by <= box_y2[4] && ene[dead + 44])
							              {
								              ene[dead + 44] = false;
											  enemy--;
								              by = -10;
								              bullet = false;
											  score1 = score1+10;
											  cout << score1;
							              }
							           if (by >= box_y1[3] && by <= box_y2[3] && ene[dead + 33])
							              {
								              ene[dead + 33] = false;
											  enemy--;
								              by = -10;
								              bullet = false;
											  score1 = score1+10;
											  cout << score1;
							              }
							           if (by >= box_y1[2] && by <= box_y2[2] && ene[dead + 22])
							              {
								              ene[dead + 22] = false;
											  enemy--;
								              by = -10;
								              bullet = false;
											  score1 = score1+10;
											  cout << score1;
							              }
							           if ((by >= box_y1[1] && by <= box_y2[1]) && ene[dead + 11])
							              {
								               ene[dead + 11] = false;
											   enemy--;
								               by = -10;
								               bullet = false;
											   score1 = score1+10;
											   cout << score1;
							              }
							           if (by >= box_y1[0] && by <= box_y2[0] && ene[dead])
							              {
								              ene[dead] = false;
											  enemy--;
								              by = -10;
								              bullet = false;
											  score1 = score1+10;
											  cout << score1;
							              }
							           if (bullet == false)
							              {
								              break;
							              }
									 
									   }  
								}
								  
								if(score1 == 550)                                     // This will end the game as player has destroyed all the alliens and have won the match.
								  {
									lose=false;
									if (lose == false)
									   {
										  PlaceCursor(70,13);
										  myDrawText (335, 222, 150, vic, RGB(255, 255, 255), RGB(0,0,0));
										  cin >> choice;
			                              if (choice == 'y')
										  {
				                             play=true;
											 life1=3;
											 score1=0;
										  }

			                              else 
											  if (choice == 'n') 
											  {
											       play=false;
											  }
									   }
								  }								
						 }

				        myEllipse(bx - 6, by  - 6, bx + 5, by + 8, RGB(12, 12, 12), RGB(12, 12, 12));      // This clears the prints of bullet left behind.
			   }


						   	if ((ch == 32) && (!bullet))                     // This will shoot the bullet when specific key is pressed.
			                   {                                             
				                   bullet = true;
				                   bx = box_x-4;
				                   by = box_y;
							   }
							if (bullet)
			                   {
				                   myEllipse(bx - 3, by - 5, bx + 3, by + 5, RGB(255, 255, 0), RGB(255, 255, 255));        // This will draw the bullet.
			                   } 
							if (by<0)
							   {
								bullet = false;                        // This will draw the bullet even after missing the alliens.
							   }

						for(i=0; i<1; i++)
						{
							for (q = 0; q < 11; q++)
					        {       
						             if (box_x - 5 >= box_x1[q] && box_x - 5 <= box_x2[q])
						                  {                                                                             // Checks for the collision b/w the enemy and the player.
							           if (box_y - 2 >= box_y1[4] && box_y - 2 <= box_y2[4] && ene[q + 44])
							              {
								          life1--;
										  fstream file("inispace.txt");
										  file >> box_x;
										  file >> box_y;
										  file.close();
										  myRect (box_x - 30, box_y, box_x + 20, box_y + 8, RGB(12,12,12), RGB(12,12,12));
						        myRect (box_x - 10, box_y - 5, box_x, box_y, RGB(12,12,12), RGB(12,12,12));	
						        myEllipse (box_x-30 , box_y+20 , box_x-40, box_y-10, RGB(12,12,12), RGB(12,12,12));	
						        myEllipse (box_x+20 , box_y+20 , box_x+30, box_y-10, RGB(12,12,12), RGB(12,12,12));
							              }
									   if (box_y - 2 >= box_y1[3] && box_y - 2<= box_y2[3] && ene[q + 33])
							              {
								          life1--;
										  fstream file("inispace.txt");
										  file >> box_x;
										  file >> box_y;
										  file.close();
										  myRect (box_x - 30, box_y, box_x + 20, box_y + 8, RGB(12,12,12), RGB(12,12,12));
						        myRect (box_x - 10, box_y - 5, box_x, box_y, RGB(12,12,12), RGB(12,12,12));	
						        myEllipse (box_x-30 , box_y+20 , box_x-40, box_y-10, RGB(12,12,12), RGB(12,12,12));	
						        myEllipse (box_x+20 , box_y+20 , box_x+30, box_y-10, RGB(12,12,12), RGB(12,12,12));
							              }
							           if (box_y - 2>= box_y1[2] && box_y -  2<= box_y2[2] && ene[q + 22])
							              {
								          life1--;
										  fstream file("inispace.txt");
										  file >> box_x;
										  file >> box_y;
										  file.close();
										  myRect (box_x - 30, box_y, box_x + 20, box_y + 8, RGB(12,12,12), RGB(12,12,12));
						        myRect (box_x - 10, box_y - 5, box_x, box_y, RGB(12,12,12), RGB(12,12,12));	
						        myEllipse (box_x-30 , box_y+20 , box_x-40, box_y-10, RGB(12,12,12), RGB(12,12,12));	
						        myEllipse (box_x+20 , box_y+20 , box_x+30, box_y-10, RGB(12,12,12), RGB(12,12,12));
							              }
							           if (box_y - 2>= box_y1[1] && box_y - 2 <= box_y2[1] && ene[q + 11])
							              {
								          life1--;
										  fstream file("inispace.txt");
										  file >> box_x;
										  file >> box_y;
										  file.close();
										  myRect (box_x - 30, box_y, box_x + 20, box_y + 8, RGB(12,12,12), RGB(12,12,12));
						        myRect (box_x - 10, box_y - 5, box_x, box_y, RGB(12,12,12), RGB(12,12,12));	
						        myEllipse (box_x-30 , box_y+20 , box_x-40, box_y-10, RGB(12,12,12), RGB(12,12,12));	
						        myEllipse (box_x+20 , box_y+20 , box_x+30, box_y-10, RGB(12,12,12), RGB(12,12,12));
							              }
							           if (box_y - 2>= box_y1[0] && box_y - 2<= box_y2[0] && ene[q])
							              {
								          life1--;
										  fstream file("inispace.txt");
										  file >> box_x;
										  file >> box_y;
										  file.close();
										 myRect (box_x - 30, box_y, box_x + 20, box_y + 8, RGB(12,12,12), RGB(12,12,12));
						        myRect (box_x - 10, box_y - 5, box_x, box_y, RGB(12,12,12), RGB(12,12,12));	
						        myEllipse (box_x-30 , box_y+20 , box_x-40, box_y-10, RGB(12,12,12), RGB(12,12,12));	
						        myEllipse (box_x+20 , box_y+20 , box_x+30, box_y-10, RGB(12,12,12), RGB(12,12,12));
							              }
									 }
							}
						}

			  if (life1 == 0)
			  {
					win=false;                         
					break;
			  }


		} // First loop closing braket

		if (life1 == 0 && win == false)
		{
			PlaceCursor(80,13);
			myDrawText(335, 222, 150, lives, RGB(255, 255, 255), RGB(0,0,0));
			cin >> choice;                                                           // This will ask the player whether he wants to play again or not.
			 if (choice == 'y')
			 {
				 life1=3;
				 score1=0;
				 play=true;
				 win=true;
			 }
			 else
				 if (choice == 'n')
				 {
				     play=false;
					 lose=false;
				 }
		}

		if (win == false && lose == false)
		{
			break;
		}

		if (win == false)
		{
		     PlaceCursor(73,14);
			 myDrawText (335, 222, 150, loss, RGB(255, 255, 255), RGB(0,0,0));
			 cin >> choice;                                                           // This will ask the player whether he wants to play again or not.
			 if (choice == 'y')
			 {
				 life1=3;
				 score1=0;
				 play=true;
			 }
			 else
				 if (choice == 'n')
				 {
				     play=false;
				 }
		}

		if (score1 == 550)                                                           //This will tell whether player has won or not.
		{
			flag2=true;                            
		}
		else 
			if (score1 < 550)
			{
				flag2=false;
			}
		

  } // Second Loop closing braket.

    system("cls");
		     
		if (play == false && flag3 == false)
	    {
			  cout << endl << endl << endl;
			  cout << " \t\t\t\t\t\t You Exited the Game !" << endl;
		}
		else 
			if (play == false && flag2 == false || life1 == 0)
		{
			  cout << endl << endl << endl;
              cout << "\t\t\t\t\t You lost the Game ! Better Luck next time." << endl;
		}
		else 
			if (play == false && flag2 == true && life1!=0)
		    {
			  cout << endl << endl << endl;
			  cout << " \t\t\t\t\t\t You won the Game !" << endl;
			}

cout << endl << endl << endl;

			storeScore(score1);                         // This calls the function to save the score.
			displaymax(score2);                         // This calls the function to display highest scores.

  cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
}



else if(lvl == 2){                       // Medium level.
	string sg;
	bool play=true;
	bool flag2=true;
	bool flag3=true;
	int life1=2;
	int score1=0;
	int score2[500];  

while(play)         // This is the first loop from where the initialization and game start.
{
	int i,q,k;
	int enemy=55;
    int win_x, win_y;
	int move,dead;
	float box_x1[100] = {245};
	float box_y1[100] = {20};
	float box_x2[100] = {};
	float box_y2[100] = {}; 
	int ene[100] = {};
	bool bullet=false, win=true,lose=true , flag=true, pressed = false;
	char life[]="Life : ";
	char score[]="score :";char vic[]="You Won !!! Play Again ? (Y/N):"; char loss[]="You lost !!! TRY AGAIN ? (Y/N):";
	char exit[]="Game Paused !!! Do you want to Exit the game ? (Y/N):";
	char lives[] = "All Lives used !!! Do you want to try again (Y/N) ???";
	char choice;
	int bx=1000, by=1000;
	char Space_Invaders[] = "Space Invaders";
	float box_x;
	float box_y; 
	int ball_x;
	int ball_y;
	int ball_x1;
	int ball_y1;
	int ball_x2;
	int ball_y2;
	float b=0.5;
	GetWindowDimensions(win_x, win_y);
    box_x = win_x / 2;                                                  // This block controls the location of spaceship.
    box_y = win_y - 20;

	    for (move=1; move<=11; move++)
		{
			box_x1[move] = box_x1[move - 1] + 45;
		}
		for (move=0; move<11; move++)
		{
			box_x2[move] = box_x1[move] + 20;                              // This block contols the size of alliens.
		}
		for (move=1; move<=5; move++)
		{
			box_y1[move] = box_y1[move - 1] + 40;
		}
		for (move=0; move<5; move++)
		{
			box_y2[move] = box_y1[move] + 20;
		}
		for (move=0; move<=55; move++)
		{
			ene[move] = true;
		}
       system("cls");

   while (win && lose)                                                   // This is the second loop where all the event happens. 
		{
	        ball_x = (win_x / 2) + 436;
            ball_y = (win_y / 2) - 222;                                  // This draws the life. 
	        ball_x1 = (win_x / 2) + 450;
            ball_y1 = (win_y / 2) - 222;
            ball_x2 = (win_x / 2) + 464;
            ball_y2 = (win_y / 2) - 222;

			PlaceCursor(8,1);
			myLine(0, 5, win_x, 5, RGB(255,255,0));
		    myLine(win_x, 5, win_x, win_y, RGB(255,255,0));                  // These lines draw the borders.
		    myLine(0, win_y, win_x, win_y, RGB(255,255,0));
		    myLine(0, 5, 0, win_y, RGB(255,255,0));
			SetWindowTitle(Space_Invaders);
	        myDrawTextWithFont(win_x / 60, win_y / 35, 20, score, RGB(255, 255, 255), RGB(20, 20, 20));    
	        myDrawTextWithFont((win_x / 2) + 395, (win_y / 2) - 225, 20, life, RGB(255, 255, 255), RGB(20, 20, 20));   // This draw the text.    
			myEllipse(ball_x, ball_y, ball_x + 10, ball_y + 15, RGB(255, 0, 0), RGB(255, 0, 0));
			myEllipse(ball_x1, ball_y1, ball_x1 + 10, ball_y1 + 15, RGB(255, 0, 0), RGB(255, 0, 0));
			myEllipse(ball_x2, ball_y2, ball_x2 + 10, ball_y2 + 15, RGB(255, 0, 0), RGB(255, 0, 0));						   
		 
			if (life1 == 2)
			{
					myEllipse(ball_x2, ball_y2, ball_x2 + 10, ball_y2 + 15, RGB(12, 12, 12), RGB(12, 12, 12));
			}
			if (life1 == 1)
			{
				myEllipse(ball_x2, ball_y2, ball_x2 + 10, ball_y2 + 15, RGB(12, 12, 12), RGB(12, 12, 12));
			    myEllipse(ball_x1, ball_y1, ball_x1 + 10, ball_y1 + 15, RGB(12, 12, 12), RGB(12, 12, 12));
			}
			if (life1 == 0)
			{
				myEllipse(ball_x, ball_y, ball_x + 10, ball_y + 15, RGB(12, 12, 12), RGB(12, 12, 12));
				myEllipse(ball_x2, ball_y2, ball_x2 + 10, ball_y2 + 15, RGB(12, 12, 12), RGB(12, 12, 12));
			    myEllipse(ball_x1, ball_y1, ball_x1 + 10, ball_y1 + 15, RGB(12, 12, 12), RGB(12, 12, 12));
			}
			for (i=0; i<11; i++)                                // This block will clear previously drawn aliens.
			   {
					myRect (box_x1[i], box_y1[0], box_x2[i], box_y2[0], RGB(12, 12, 12), RGB(12, 12, 12));
					myRect (box_x1[i], box_y1[1], box_x2[i], box_y2[1], RGB(12, 12, 12), RGB(12, 12, 12));
					myRect (box_x1[i], box_y1[2], box_x2[i], box_y2[2], RGB(12, 12, 12), RGB(12, 12, 12));
					myRect (box_x1[i], box_y1[3], box_x2[i], box_y2[3], RGB(12, 12, 12), RGB(12, 12, 12));
					myRect (box_x1[i], box_y1[4], box_x2[i], box_y2[4], RGB(12, 12, 12), RGB(12, 12, 12));
		       }

			for (move=0; move<5; move++)                                // This controls the movement of aliens downwards.
				{
					  if(box_y1[move] < 480 && box_y2[move] < 480)
					  {
				    	box_y1[move] += 0.3;
					    box_y2[move] += 0.3;
					  }
					else
					{
						win=false;
						break;
					}
				}

			for (move=0; move<11; move++)                                     // This controls the movement of aliens side by side.
				{
					if (box_x1[move] < 100 || box_x1[move] > win_x-100)
						b = b*(-1);
					box_x1[move] += b;
					box_x2[move] += b;
				}
		
				for (i=0; i<11; i++)                                        // This block draws all enemies
				    {
					    if (ene[i] == true)
						    myRect (box_x1[i], box_y1[0], box_x2[i], box_y2[0], RGB(0, 153, 0), RGB(0, 255, 0));
					    if (ene[i + 11] == true)
						    myRect (box_x1[i], box_y1[1], box_x2[i], box_y2[1], RGB(0, 153, 0), RGB(0, 255, 0));
					    if (ene[i + 22] == true)
						    myRect (box_x1[i], box_y1[2], box_x2[i], box_y2[2], RGB(0, 153, 0), RGB(0, 255, 0));
				    	if (ene[i + 33] == true)
						    myRect (box_x1[i], box_y1[3], box_x2[i], box_y2[3], RGB(0, 153, 0), RGB(0, 255, 0));
					    if (ene[i + 44] == true)
						    myRect (box_x1[i], box_y1[4], box_x2[i], box_y2[4], RGB(0, 153, 0), RGB(0, 255, 0));
				    }
		
						myRect (box_x - 30, box_y, box_x + 20, box_y + 8, RGB(224, 224, 224), RGB(224, 224, 224));    // This draws the Spaceship.
						myRect (box_x - 10, box_y - 5, box_x, box_y, RGB(224, 224, 224), RGB(224, 224, 224));	
						myEllipse (box_x - 30 , box_y + 20 , box_x - 40, box_y - 10, RGB(192, 192, 192), RGB(224, 224, 224));	
						myEllipse (box_x + 20 , box_y + 20 , box_x + 30, box_y - 10, RGB(192, 192, 192), RGB(224, 224, 224));	
						int ch = CheckKeyPressed();                   // This block controls the movement of spaceship and also make spaceship move in borders;
                           if (ch == LEFTKEY)
						   {
					            myRect (box_x - 30, box_y, box_x + 20, box_y + 8, RGB(12,12,12), RGB(12,12,12)); 
						        myRect (box_x - 10, box_y - 5, box_x, box_y, RGB(12,12,12), RGB(12,12,12));	                    // This removes the prints drawn by the Spaceship.
						        myEllipse (box_x-30 , box_y+20 , box_x-40, box_y-10, RGB(12,12,12), RGB(12,12,12));	
						        myEllipse (box_x+20 , box_y+20 , box_x+30, box_y-10, RGB(12,12,12), RGB(12,12,12)); 	  
						   if(box_x > 20)
							    box_x -= 20;
						   }
                           else if (ch == RIGHTKEY)
						   {
						        myRect (box_x - 30, box_y, box_x + 20, box_y + 8, RGB(12,12,12), RGB(12,12,12)); 
						        myRect (box_x - 10, box_y - 5, box_x, box_y, RGB(12,12,12), RGB(12,12,12));	
						        myEllipse (box_x-30 , box_y+20 , box_x-40, box_y-10, RGB(12,12,12), RGB(12,12,12));	
						        myEllipse (box_x+20 , box_y+20 , box_x+30, box_y-10, RGB(12,12,12), RGB(12,12,12));
						   if(box_x < 940)
                                box_x += 20;
						   }
		                   else if (ch == UPKEY)
						   {
							    myRect (box_x - 30, box_y, box_x + 20, box_y + 8, RGB(12,12,12), RGB(12,12,12));
						        myRect (box_x - 10, box_y - 5, box_x, box_y, RGB(12,12,12), RGB(12,12,12));	
						        myEllipse (box_x-30 , box_y+20 , box_x-40, box_y-10, RGB(12,12,12), RGB(12,12,12));	
						        myEllipse (box_x+20 , box_y+20 , box_x+30, box_y-10, RGB(12,12,12), RGB(12,12,12));
						   if(box_y > 20)
							    box_y -= 15; 
						   }
		                   else if (ch == DOWNKEY)
						   {
					            myRect (box_x - 30, box_y, box_x + 20, box_y + 8, RGB(12,12,12), RGB(12,12,12));           
						        myRect (box_x - 10, box_y - 5, box_x, box_y, RGB(12,12,12), RGB(12,12,12));	
						        myEllipse (box_x-30 , box_y+20 , box_x-40, box_y-10, RGB(12,12,12), RGB(12,12,12));	
						        myEllipse (box_x+20 , box_y+20 , box_x+30, box_y-10, RGB(12,12,12), RGB(12,12,12));
						   if(box_y < 450)
			                    box_y += 15;
						   }
						   else if(ch == 83)
						   {
							   fstream myfile("savedgame.txt");
							   if(myfile)
							   {
								   myfile<<i<<endl<<q<<endl<<k<<endl<<play<<endl<<flag2<<endl<<flag3<<endl<<life1<<endl<<score1<<endl<<enemy<<endl<<win_x<<endl<<win_y<<endl<<move<<endl<<dead<<endl<<box_x1[move]<<endl<<box_y1[move]<<endl<<box_x2[move]<<endl<<box_y2[move]<<endl<<ene[i]<<endl<<bullet<<endl<<win<<endl<<lose<<endl<<flag<<endl<<pressed<<endl<<bx<<endl<<by<<endl<<box_x<<endl<<box_y<<endl<<b;
								   myfile.close();
							   }
						   }
						   else if(ch == 76)
						   {
							   fstream myfile("savedgame.txt");
							   myfile>>i;
							   myfile>>q;
							   myfile>>k;
							   myfile>>play;
							   myfile>>flag2;
							   myfile>>flag3;
							   myfile>>life1;
							   myfile>>score1;
							   myfile>>enemy;
							   myfile>>win_x;
							   myfile>>win_y;
							   myfile>>move;
							   myfile>>dead;
							   myfile>>box_x1[move];
							   myfile>>box_y1[move];
							   myfile>>box_x2[move];
							   myfile>>box_y2[move];
							   myfile>>ene[i];
							   myfile>>bullet;
							   myfile>>win;
							   myfile>>lose;
							   myfile>>flag;
							   myfile>>pressed;
							   myfile>>bx;
							   myfile>>by;
							   myfile>>box_x;
							   myfile>>box_y;
							   myfile>>b;
							   ClearScreen();
							   myfile.close();
						   }
						   else if (ch == 73)
						   {
							   b=0;
						   }
						   else if (ch == 79)                              // Cheats to change the movement of alliens side by side.
						   {
							   b=0.5;
						   }
						   else if (ch == 85)
						   {
							   b=1;
						   }
						   else if (ch == 27 || ch == 80)
						   {
							   win=false;
							   lose=false;
							   	if (win == false && lose == false)
		                        {
									  PlaceCursor(90,13);
			                          myDrawText (335, 222, 150, exit, RGB(255, 255, 255), RGB(0,0,0));
			                          cin >> choice;
			                          if (choice == 'y')
									  {
			                               play=false;
									       flag3=false;                                     // This block is to exit the game ot to pause the game.
										   break;
									  }
			                          else
				                           if (choice == 'n')
										   {
				                                 play=true;
									             flag3=true;
												 win=true;
												 lose=true;
												 ClearScreen();
										   } 
		                        }
						   }
						    
			   for (k = 0; k < 10; k++)                               // This loop will control the movement of bullet
			         {	                                         
				         if (bullet) 						
				             {
					            by -= 2;                                     // This controls the movement of bullet

				                for (dead = 0; dead < 11; dead++)
					                {
						               if (bx >= box_x1[dead] && bx <= box_x2[dead])
						                  {                                                                   //Checks for collision b/w any enemy and player bullet and eliminates enemy if any.
							           if (by >= box_y1[4] && by <= box_y2[4] && ene[dead + 44])
							              {
								              ene[dead + 44] = false;
											  enemy--;
								              by = -10;
								              bullet = false;
											  score1 = score1+10;
											  cout << score1;
							              }
							           if (by >= box_y1[3] && by <= box_y2[3] && ene[dead + 33])
							              {
								              ene[dead + 33] = false;
											  enemy--;
								              by = -10;
								              bullet = false;
											  score1 = score1+10;
											  cout << score1;
							              }
							           if (by >= box_y1[2] && by <= box_y2[2] && ene[dead + 22])
							              {
								              ene[dead + 22] = false;
											  enemy--;
								              by = -10;
								              bullet = false;
											  score1 = score1+10;
											  cout << score1;
							              }
							           if ((by >= box_y1[1] && by <= box_y2[1]) && ene[dead + 11])
							              {
								               ene[dead + 11] = false;
											   enemy--;
								               by = -10;
								               bullet = false;
											   score1 = score1+10;
											   cout << score1;
							              }
							           if (by >= box_y1[0] && by <= box_y2[0] && ene[dead])
							              {
								              ene[dead] = false;
											  enemy--;
								              by = -10;
								              bullet = false;
											  score1 = score1+10;
											  cout << score1;
							              }
							           if (bullet == false)
							              {
								              break;
							              }
									 
									   }  
								}
								  
								if(score1 == 550)                                     // This will end the game as player has destroyed all the alliens and have won the match.
								  {
									lose=false;
									if (lose == false)
									   {
										  PlaceCursor(70,13);
										  myDrawText (335, 222, 150, vic, RGB(255, 255, 255), RGB(0,0,0));
										  cin >> choice;
			                              if (choice == 'y')
										  {
				                             play=true;
											 life1=2;
											 score1=0;
										  }

			                              else 
											  if (choice == 'n') 
											  {
											       play=false;
											  }
									   }
								  }								
						 }

				        myEllipse(bx - 6, by  - 6, bx + 5, by + 8, RGB(12, 12, 12), RGB(12, 12, 12));      // This clears the prints of bullet left behind.
			   }


						   	if ((ch == 32) && (!bullet))                     // This will shoot the bullet when specific key is pressed.
			                   {                                             
				                   bullet = true;
				                   bx = box_x-4;
				                   by = box_y;
							   }
							if (bullet)
			                   {
				                   myEllipse(bx - 3, by - 5, bx + 3, by + 5, RGB(255, 255, 0), RGB(255, 255, 255));        // This will draw the bullet.
			                   } 
							if (by<0)
							   {
								bullet = false;                        // This will draw the bullet even after missing the alliens.
							   }

						for(i=0; i<1; i++)
						{
							for (q = 0; q < 11; q++)
					        {       
						             if (box_x - 5 >= box_x1[q] && box_x - 5 <= box_x2[q])
						                  {                                                                             // Checks for the collision b/w the enemy and the player.
							           if (box_y - 2 >= box_y1[4] && box_y - 2 <= box_y2[4] && ene[q + 44])
							              {
								          life1--;
										  fstream file("inispace.txt");
										  file >> box_x;
										  file >> box_y;
										  file.close();
										  myRect (box_x - 30, box_y, box_x + 20, box_y + 8, RGB(12,12,12), RGB(12,12,12));
						        myRect (box_x - 10, box_y - 5, box_x, box_y, RGB(12,12,12), RGB(12,12,12));	
						        myEllipse (box_x-30 , box_y+20 , box_x-40, box_y-10, RGB(12,12,12), RGB(12,12,12));	
						        myEllipse (box_x+20 , box_y+20 , box_x+30, box_y-10, RGB(12,12,12), RGB(12,12,12));
							              }
									   if (box_y - 2 >= box_y1[3] && box_y - 2<= box_y2[3] && ene[q + 33])
							              {
								          life1--;
										  fstream file("inispace.txt");
										  file >> box_x;
										  file >> box_y;
										  file.close();
										  myRect (box_x - 30, box_y, box_x + 20, box_y + 8, RGB(12,12,12), RGB(12,12,12));
						        myRect (box_x - 10, box_y - 5, box_x, box_y, RGB(12,12,12), RGB(12,12,12));	
						        myEllipse (box_x-30 , box_y+20 , box_x-40, box_y-10, RGB(12,12,12), RGB(12,12,12));	
						        myEllipse (box_x+20 , box_y+20 , box_x+30, box_y-10, RGB(12,12,12), RGB(12,12,12));
							              }
							           if (box_y - 2>= box_y1[2] && box_y -  2<= box_y2[2] && ene[q + 22])
							              {
								          life1--;
										  fstream file("inispace.txt");
										  file >> box_x;
										  file >> box_y;
										  file.close();
										  myRect (box_x - 30, box_y, box_x + 20, box_y + 8, RGB(12,12,12), RGB(12,12,12));
						        myRect (box_x - 10, box_y - 5, box_x, box_y, RGB(12,12,12), RGB(12,12,12));	
						        myEllipse (box_x-30 , box_y+20 , box_x-40, box_y-10, RGB(12,12,12), RGB(12,12,12));	
						        myEllipse (box_x+20 , box_y+20 , box_x+30, box_y-10, RGB(12,12,12), RGB(12,12,12));
							              }
							           if (box_y - 2>= box_y1[1] && box_y - 2 <= box_y2[1] && ene[q + 11])
							              {
								          life1--;
										  fstream file("inispace.txt");
										  file >> box_x;
										  file >> box_y;
										  file.close();
										  myRect (box_x - 30, box_y, box_x + 20, box_y + 8, RGB(12,12,12), RGB(12,12,12));
						        myRect (box_x - 10, box_y - 5, box_x, box_y, RGB(12,12,12), RGB(12,12,12));	
						        myEllipse (box_x-30 , box_y+20 , box_x-40, box_y-10, RGB(12,12,12), RGB(12,12,12));	
						        myEllipse (box_x+20 , box_y+20 , box_x+30, box_y-10, RGB(12,12,12), RGB(12,12,12));
							              }
							           if (box_y - 2>= box_y1[0] && box_y - 2<= box_y2[0] && ene[q])
							              {
								          life1--;
										  fstream file("inispace.txt");
										  file >> box_x;
										  file >> box_y;
										  file.close();
										 myRect (box_x - 30, box_y, box_x + 20, box_y + 8, RGB(12,12,12), RGB(12,12,12));
						        myRect (box_x - 10, box_y - 5, box_x, box_y, RGB(12,12,12), RGB(12,12,12));	
						        myEllipse (box_x-30 , box_y+20 , box_x-40, box_y-10, RGB(12,12,12), RGB(12,12,12));	
						        myEllipse (box_x+20 , box_y+20 , box_x+30, box_y-10, RGB(12,12,12), RGB(12,12,12));
							              }
									 }
							}
						}

			  if (life1 == 0)
			  {
					win=false;                         
					break;
			  }


		} // First loop closing braket

		if (life1 == 0 && win == false)
		{
			PlaceCursor(80,13);
			myDrawText(335, 222, 150, lives, RGB(255, 255, 255), RGB(0,0,0));
			cin >> choice;                                                           // This will ask the player whether he wants to play again or not.
			 if (choice == 'y')
			 {
				 life1=2;
				 score1=0;
				 play=true;
				 win=true;
			 }
			 else
				 if (choice == 'n')
				 {
				     play=false;
					 lose=false;
				 }
		}

		if (win == false && lose == false)
		{
			break;
		}

		if (win == false)
		{
		     PlaceCursor(73,14);
			 myDrawText (335, 222, 150, loss, RGB(255, 255, 255), RGB(0,0,0));
			 cin >> choice;                                                           // This will ask the player whether he wants to play again or not.
			 if (choice == 'y')
			 {
				 life1=2;
				 score1=0;
				 play=true;
			 }
			 else
				 if (choice == 'n')
				 {
				     play=false;
				 }
		}

		if (score1 == 550)                                                           //This will tell whether player has won or not.
		{
			flag2=true;                            
		}
		else 
			if (score1 < 550)
			{
				flag2=false;
			}
		

  } // Second Loop closing braket.

    system("cls");
		     
		if (play == false && flag3 == false)
	    {
			  cout << endl << endl << endl;
			  cout << " \t\t\t\t\t\t You Exited the Game !" << endl;
		}
		else 
			if (play == false && flag2 == false || life1 == 0)
		{
			  cout << endl << endl << endl;
              cout << "\t\t\t\t\t You lost the Game ! Better Luck next time." << endl;
		}
		else 
			if (play == false && flag2 == true && life1!=0)
		    {
			  cout << endl << endl << endl;
			  cout << " \t\t\t\t\t\t You won the Game !" << endl;
			}

cout << endl << endl << endl;

			storeScore(score1);                         // This calls the function to save the score.
			displaymax(score2);                         // This calls the function to display highest scores.

  cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
}



else if(lvl == 3)
{                       // Hard level.
	string sg;
	bool play=true;
	bool flag2=true;
	bool flag3=true;
	int life1=1;
	int score1=0;
	int score2[500];  

while(play)         // This is the first loop from where the initialization and game start.
{
	int i,q,k;
	int enemy=55;
    int win_x, win_y;
	int move,dead;
	float box_x1[100] = {245};
	float box_y1[100] = {20};
	float box_x2[100] = {};
	float box_y2[100] = {}; 
	int ene[100] = {};
	bool bullet=false, win=true,lose=true , flag=true, pressed = false;
	char life[]="Life : ";
	char score[]="score :";char vic[]="You Won !!! Play Again ? (Y/N):"; char loss[]="You lost !!! TRY AGAIN ? (Y/N):";
	char exit[]="Game Paused !!! Do you want to Exit the game ? (Y/N):";
	char lives[] = "All Lives used !!! Do you want to try again (Y/N) ???";
	char choice;
	int bx=1000, by=1000;
	char Space_Invaders[] = "Space Invaders";
	float box_x;
	float box_y; 
	int ball_x;
	int ball_y;
	int ball_x1;
	int ball_y1;
	int ball_x2;
	int ball_y2;
	float b=1;
	GetWindowDimensions(win_x, win_y);
    box_x = win_x / 2;                                                  // This block controls the location of spaceship.
    box_y = win_y - 20;

	    for (move=1; move<=11; move++)
		{
			box_x1[move] = box_x1[move - 1] + 45;
		}
		for (move=0; move<11; move++)
		{
			box_x2[move] = box_x1[move] + 20;                              // This block contols the size of alliens.
		}
		for (move=1; move<=5; move++)
		{
			box_y1[move] = box_y1[move - 1] + 40;
		}
		for (move=0; move<5; move++)
		{
			box_y2[move] = box_y1[move] + 20;
		}
		for (move=0; move<=55; move++)
		{
			ene[move] = true;
		}
       system("cls");

   while (win && lose)                                                   // This is the second loop where all the event happens. 
		{
	        ball_x = (win_x / 2) + 436;
            ball_y = (win_y / 2) - 222;                                  // This draws the life. 
	        ball_x1 = (win_x / 2) + 450;
            ball_y1 = (win_y / 2) - 222;
            ball_x2 = (win_x / 2) + 464;
            ball_y2 = (win_y / 2) - 222;

			PlaceCursor(8,1);
			myLine(0, 5, win_x, 5, RGB(255,255,0));
		    myLine(win_x, 5, win_x, win_y, RGB(255,255,0));                  // These lines draw the borders.
		    myLine(0, win_y, win_x, win_y, RGB(255,255,0));
		    myLine(0, 5, 0, win_y, RGB(255,255,0));
			SetWindowTitle(Space_Invaders);
	        myDrawTextWithFont(win_x / 60, win_y / 35, 20, score, RGB(255, 255, 255), RGB(20, 20, 20));    
	        myDrawTextWithFont((win_x / 2) + 395, (win_y / 2) - 225, 20, life, RGB(255, 255, 255), RGB(20, 20, 20));   // This draw the text.    
			myEllipse(ball_x, ball_y, ball_x + 10, ball_y + 15, RGB(255, 0, 0), RGB(255, 0, 0));
			myEllipse(ball_x1, ball_y1, ball_x1 + 10, ball_y1 + 15, RGB(255, 0, 0), RGB(255, 0, 0));
			myEllipse(ball_x2, ball_y2, ball_x2 + 10, ball_y2 + 15, RGB(255, 0, 0), RGB(255, 0, 0));						   
		 
			if (life1 == 2)
			{
					myEllipse(ball_x2, ball_y2, ball_x2 + 10, ball_y2 + 15, RGB(12, 12, 12), RGB(12, 12, 12));
			}
			if (life1 == 1)
			{
				myEllipse(ball_x2, ball_y2, ball_x2 + 10, ball_y2 + 15, RGB(12, 12, 12), RGB(12, 12, 12));
			    myEllipse(ball_x1, ball_y1, ball_x1 + 10, ball_y1 + 15, RGB(12, 12, 12), RGB(12, 12, 12));
			}
			if (life1 == 0)
			{
				myEllipse(ball_x, ball_y, ball_x + 10, ball_y + 15, RGB(12, 12, 12), RGB(12, 12, 12));
				myEllipse(ball_x2, ball_y2, ball_x2 + 10, ball_y2 + 15, RGB(12, 12, 12), RGB(12, 12, 12));
			    myEllipse(ball_x1, ball_y1, ball_x1 + 10, ball_y1 + 15, RGB(12, 12, 12), RGB(12, 12, 12));
			}
			for (i=0; i<11; i++)                                // This block will clear previously drawn aliens.
			   {
					myRect (box_x1[i], box_y1[0], box_x2[i], box_y2[0], RGB(12, 12, 12), RGB(12, 12, 12));
					myRect (box_x1[i], box_y1[1], box_x2[i], box_y2[1], RGB(12, 12, 12), RGB(12, 12, 12));
					myRect (box_x1[i], box_y1[2], box_x2[i], box_y2[2], RGB(12, 12, 12), RGB(12, 12, 12));
					myRect (box_x1[i], box_y1[3], box_x2[i], box_y2[3], RGB(12, 12, 12), RGB(12, 12, 12));
					myRect (box_x1[i], box_y1[4], box_x2[i], box_y2[4], RGB(12, 12, 12), RGB(12, 12, 12));
		       }

			for (move=0; move<5; move++)                                // This controls the movement of aliens downwards.
				{
					  if(box_y1[move] < 480 && box_y2[move] < 480)
					  {
				    	box_y1[move] += 0.2;
					    box_y2[move] += 0.2;
					  }
					else
					{
						win=false;
						break;
					}
				}

			for (move=0; move<11; move++)                                     // This controls the movement of aliens side by side.
				{
					if (box_x1[move] < 100 || box_x1[move] > win_x-100)
						b = b*(-1);
					box_x1[move] += b;
					box_x2[move] += b;
				}
		
				for (i=0; i<11; i++)                                        // This block draws all enemies
				    {
					    if (ene[i] == true)
						    myRect (box_x1[i], box_y1[0], box_x2[i], box_y2[0], RGB(0, 153, 0), RGB(0, 255, 0));
					    if (ene[i + 11] == true)
						    myRect (box_x1[i], box_y1[1], box_x2[i], box_y2[1], RGB(0, 153, 0), RGB(0, 255, 0));
					    if (ene[i + 22] == true)
						    myRect (box_x1[i], box_y1[2], box_x2[i], box_y2[2], RGB(0, 153, 0), RGB(0, 255, 0));
				    	if (ene[i + 33] == true)
						    myRect (box_x1[i], box_y1[3], box_x2[i], box_y2[3], RGB(0, 153, 0), RGB(0, 255, 0));
					    if (ene[i + 44] == true)
						    myRect (box_x1[i], box_y1[4], box_x2[i], box_y2[4], RGB(0, 153, 0), RGB(0, 255, 0));
				    }
		
						myRect (box_x - 30, box_y, box_x + 20, box_y + 8, RGB(224, 224, 224), RGB(224, 224, 224));    // This draws the Spaceship.
						myRect (box_x - 10, box_y - 5, box_x, box_y, RGB(224, 224, 224), RGB(224, 224, 224));	
						myEllipse (box_x - 30 , box_y + 20 , box_x - 40, box_y - 10, RGB(192, 192, 192), RGB(224, 224, 224));	
						myEllipse (box_x + 20 , box_y + 20 , box_x + 30, box_y - 10, RGB(192, 192, 192), RGB(224, 224, 224));	
						int ch = CheckKeyPressed();                   // This block controls the movement of spaceship and also make spaceship move in borders;
                           if (ch == LEFTKEY)
						   {
					            myRect (box_x - 30, box_y, box_x + 20, box_y + 8, RGB(12,12,12), RGB(12,12,12)); 
						        myRect (box_x - 10, box_y - 5, box_x, box_y, RGB(12,12,12), RGB(12,12,12));	                    // This removes the prints drawn by the Spaceship.
						        myEllipse (box_x-30 , box_y+20 , box_x-40, box_y-10, RGB(12,12,12), RGB(12,12,12));	
						        myEllipse (box_x+20 , box_y+20 , box_x+30, box_y-10, RGB(12,12,12), RGB(12,12,12)); 	  
						   if(box_x > 20)
							    box_x -= 20;
						   }
                           else if (ch == RIGHTKEY)
						   {
						        myRect (box_x - 30, box_y, box_x + 20, box_y + 8, RGB(12,12,12), RGB(12,12,12)); 
						        myRect (box_x - 10, box_y - 5, box_x, box_y, RGB(12,12,12), RGB(12,12,12));	
						        myEllipse (box_x-30 , box_y+20 , box_x-40, box_y-10, RGB(12,12,12), RGB(12,12,12));	
						        myEllipse (box_x+20 , box_y+20 , box_x+30, box_y-10, RGB(12,12,12), RGB(12,12,12));
						   if(box_x < 940)
                                box_x += 20;
						   }
		                   else if (ch == UPKEY)
						   {
							    myRect (box_x - 30, box_y, box_x + 20, box_y + 8, RGB(12,12,12), RGB(12,12,12));
						        myRect (box_x - 10, box_y - 5, box_x, box_y, RGB(12,12,12), RGB(12,12,12));	
						        myEllipse (box_x-30 , box_y+20 , box_x-40, box_y-10, RGB(12,12,12), RGB(12,12,12));	
						        myEllipse (box_x+20 , box_y+20 , box_x+30, box_y-10, RGB(12,12,12), RGB(12,12,12));
						   if(box_y > 20)
							    box_y -= 15; 
						   }
		                   else if (ch == DOWNKEY)
						   {
					            myRect (box_x - 30, box_y, box_x + 20, box_y + 8, RGB(12,12,12), RGB(12,12,12));           
						        myRect (box_x - 10, box_y - 5, box_x, box_y, RGB(12,12,12), RGB(12,12,12));	
						        myEllipse (box_x-30 , box_y+20 , box_x-40, box_y-10, RGB(12,12,12), RGB(12,12,12));	
						        myEllipse (box_x+20 , box_y+20 , box_x+30, box_y-10, RGB(12,12,12), RGB(12,12,12));
						   if(box_y < 450)
			                    box_y += 15;
						   }
						   else if(ch == 83)
						   {
							   fstream myfile("savedgame.txt");
							   if(myfile)
							   {
								   myfile<<i<<endl<<q<<endl<<k<<endl<<play<<endl<<flag2<<endl<<flag3<<endl<<life1<<endl<<score1<<endl<<enemy<<endl<<win_x<<endl<<win_y<<endl<<move<<endl<<dead<<endl<<box_x1[move]<<endl<<box_y1[move]<<endl<<box_x2[move]<<endl<<box_y2[move]<<endl<<ene[i]<<endl<<bullet<<endl<<win<<endl<<lose<<endl<<flag<<endl<<pressed<<endl<<bx<<endl<<by<<endl<<box_x<<endl<<box_y<<endl<<b;
								   myfile.close();
							   }
						   }
						   else if(ch == 76)
						   {
							   fstream myfile("savedgame.txt");
							   myfile>>i;
							   myfile>>q;
							   myfile>>k;
							   myfile>>play;
							   myfile>>flag2;
							   myfile>>flag3;
							   myfile>>life1;
							   myfile>>score1;
							   myfile>>enemy;
							   myfile>>win_x;
							   myfile>>win_y;
							   myfile>>move;
							   myfile>>dead;
							   myfile>>box_x1[move];
							   myfile>>box_y1[move];
							   myfile>>box_x2[move];
							   myfile>>box_y2[move];
							   myfile>>ene[i];
							   myfile>>bullet;
							   myfile>>win;
							   myfile>>lose;
							   myfile>>flag;
							   myfile>>pressed;
							   myfile>>bx;
							   myfile>>by;
							   myfile>>box_x;
							   myfile>>box_y;
							   myfile>>b;
							   ClearScreen();
							   myfile.close();
						   }
						   else if (ch == 73)
						   {
							   b=0;
						   }
						   else if (ch == 79)                              // Cheats to change the movement of alliens side by side.
						   {
							   b=0.5;
						   }
						   else if (ch == 85)
						   {
							   b=1;
						   }
						   else if (ch == 27 || ch == 80)
						   {
							   win=false;
							   lose=false;
							   	if (win == false && lose == false)
		                        {
									  PlaceCursor(90,13);
			                          myDrawText (335, 222, 150, exit, RGB(255, 255, 255), RGB(0,0,0));
			                          cin >> choice;
			                          if (choice == 'y')
									  {
			                               play=false;
									       flag3=false;                                     // This block is to exit the game ot to pause the game.
										   break;
									  }
			                          else
				                           if (choice == 'n')
										   {
				                                 play=true;
									             flag3=true;
												 win=true;
												 lose=true;
												 ClearScreen();
										   } 
		                        }
						   }
						    
			   for (k = 0; k < 10; k++)                               // This loop will control the movement of bullet
			         {	                                         
				         if (bullet) 						
				             {
					            by -= 1;                                     // This controls the movement of bullet

				                for (dead = 0; dead < 11; dead++)
					                {
						               if (bx >= box_x1[dead] && bx <= box_x2[dead])
						                  {                                                                   //Checks for collision b/w any enemy and player bullet and eliminates enemy if any.
							           if (by >= box_y1[4] && by <= box_y2[4] && ene[dead + 44])
							              {
								              ene[dead + 44] = false;
											  enemy--;
								              by = -10;
								              bullet = false;
											  score1 = score1+10;
											  cout << score1;
							              }
							           if (by >= box_y1[3] && by <= box_y2[3] && ene[dead + 33])
							              {
								              ene[dead + 33] = false;
											  enemy--;
								              by = -10;
								              bullet = false;
											  score1 = score1+10;
											  cout << score1;
							              }
							           if (by >= box_y1[2] && by <= box_y2[2] && ene[dead + 22])
							              {
								              ene[dead + 22] = false;
											  enemy--;
								              by = -10;
								              bullet = false;
											  score1 = score1+10;
											  cout << score1;
							              }
							           if ((by >= box_y1[1] && by <= box_y2[1]) && ene[dead + 11])
							              {
								               ene[dead + 11] = false;
											   enemy--;
								               by = -10;
								               bullet = false;
											   score1 = score1+10;
											   cout << score1;
							              }
							           if (by >= box_y1[0] && by <= box_y2[0] && ene[dead])
							              {
								              ene[dead] = false;
											  enemy--;
								              by = -10;
								              bullet = false;
											  score1 = score1+10;
											  cout << score1;
							              }
							           if (bullet == false)
							              {
								              break;
							              }
									 
									   }  
								}
								  
								if(score1 == 550)                                     // This will end the game as player has destroyed all the alliens and have won the match.
								  {
									lose=false;
									if (lose == false)
									   {
										  PlaceCursor(70,13);
										  myDrawText (335, 222, 150, vic, RGB(255, 255, 255), RGB(0,0,0));
										  cin >> choice;
			                              if (choice == 'y')
										  {
				                             play=true;
											 life1=1;
											 score1=0;
										  }

			                              else 
											  if (choice == 'n') 
											  {
											       play=false;
											  }
									   }
								  }								
						 }

				        myEllipse(bx - 6, by  - 6, bx + 5, by + 8, RGB(12, 12, 12), RGB(12, 12, 12));      // This clears the prints of bullet left behind.
			   }


						   	if ((ch == 32) && (!bullet))                     // This will shoot the bullet when specific key is pressed.
			                   {                                             
				                   bullet = true;
				                   bx = box_x-4;
				                   by = box_y;
							   }
							if (bullet)
			                   {
				                   myEllipse(bx - 3, by - 5, bx + 3, by + 5, RGB(255, 255, 0), RGB(255, 255, 255));        // This will draw the bullet.
			                   } 
							if (by<0)
							   {
								bullet = false;                        // This will draw the bullet even after missing the alliens.
							   }

						for(i=0; i<1; i++)
						{
							for (q = 0; q < 11; q++)
					        {       
						             if (box_x - 5 >= box_x1[q] && box_x - 5 <= box_x2[q])
						                  {                                                                             // Checks for the collision b/w the enemy and the player.
							           if (box_y - 2 >= box_y1[4] && box_y - 2 <= box_y2[4] && ene[q + 44])
							              {
								          life1--;
										  fstream file("inispace.txt");
										  file >> box_x;
										  file >> box_y;
										  file.close();
										  myRect (box_x - 30, box_y, box_x + 20, box_y + 8, RGB(12,12,12), RGB(12,12,12));
						        myRect (box_x - 10, box_y - 5, box_x, box_y, RGB(12,12,12), RGB(12,12,12));	
						        myEllipse (box_x-30 , box_y+20 , box_x-40, box_y-10, RGB(12,12,12), RGB(12,12,12));	
						        myEllipse (box_x+20 , box_y+20 , box_x+30, box_y-10, RGB(12,12,12), RGB(12,12,12));
							              }
									   if (box_y - 2 >= box_y1[3] && box_y - 2<= box_y2[3] && ene[q + 33])
							              {
								          life1--;
										  fstream file("inispace.txt");
										  file >> box_x;
										  file >> box_y;
										  file.close();
										  myRect (box_x - 30, box_y, box_x + 20, box_y + 8, RGB(12,12,12), RGB(12,12,12));
						        myRect (box_x - 10, box_y - 5, box_x, box_y, RGB(12,12,12), RGB(12,12,12));	
						        myEllipse (box_x-30 , box_y+20 , box_x-40, box_y-10, RGB(12,12,12), RGB(12,12,12));	
						        myEllipse (box_x+20 , box_y+20 , box_x+30, box_y-10, RGB(12,12,12), RGB(12,12,12));
							              }
							           if (box_y - 2>= box_y1[2] && box_y -  2<= box_y2[2] && ene[q + 22])
							              {
								          life1--;
										  fstream file("inispace.txt");
										  file >> box_x;
										  file >> box_y;
										  file.close();
										  myRect (box_x - 30, box_y, box_x + 20, box_y + 8, RGB(12,12,12), RGB(12,12,12));
						        myRect (box_x - 10, box_y - 5, box_x, box_y, RGB(12,12,12), RGB(12,12,12));	
						        myEllipse (box_x-30 , box_y+20 , box_x-40, box_y-10, RGB(12,12,12), RGB(12,12,12));	
						        myEllipse (box_x+20 , box_y+20 , box_x+30, box_y-10, RGB(12,12,12), RGB(12,12,12));
							              }
							           if (box_y - 2>= box_y1[1] && box_y - 2 <= box_y2[1] && ene[q + 11])
							              {
								          life1--;
										  fstream file("inispace.txt");
										  file >> box_x;
										  file >> box_y;
										  file.close();
										  myRect (box_x - 30, box_y, box_x + 20, box_y + 8, RGB(12,12,12), RGB(12,12,12));
						        myRect (box_x - 10, box_y - 5, box_x, box_y, RGB(12,12,12), RGB(12,12,12));	
						        myEllipse (box_x-30 , box_y+20 , box_x-40, box_y-10, RGB(12,12,12), RGB(12,12,12));	
						        myEllipse (box_x+20 , box_y+20 , box_x+30, box_y-10, RGB(12,12,12), RGB(12,12,12));
							              }
							           if (box_y - 2>= box_y1[0] && box_y - 2<= box_y2[0] && ene[q])
							              {
								          life1--;
										  fstream file("inispace.txt");
										  file >> box_x;
										  file >> box_y;
										  file.close();
										 myRect (box_x - 30, box_y, box_x + 20, box_y + 8, RGB(12,12,12), RGB(12,12,12));
						      
										 myRect (box_x - 10, box_y - 5, box_x, box_y, RGB(12,12,12), RGB(12,12,12));	
						        myEllipse (box_x-30 , box_y+20 , box_x-40, box_y-10, RGB(12,12,12), RGB(12,12,12));	
						        myEllipse (box_x+20 , box_y+20 , box_x+30, box_y-10, RGB(12,12,12), RGB(12,12,12));
							              }
									 }
							}
						}

			  if (life1 == 0)
			  {
					win=false;                         
					break;
			  }


		} // First loop closing braket

		if (life1 == 0 && win == false)
		{
			PlaceCursor(80,13);
			myDrawText(335, 222, 150, lives, RGB(255, 255, 255), RGB(0,0,0));
			cin >> choice;                                                           // This will ask the player whether he wants to play again or not.
			 if (choice == 'y')
			 {
				 life1=1;
				 score1=0;
				 play=true;
				 win=true;
			 }
			 else
				 if (choice == 'n')
				 {
				     play=false;
					 lose=false;
				 }
		}

		if (win == false && lose == false)
		{
			break;
		}

		if (win == false)
		{
		     PlaceCursor(73,14);
			 myDrawText (335, 222, 150, loss, RGB(255, 255, 255), RGB(0,0,0));
			 cin >> choice;                                                           // This will ask the player whether he wants to play again or not.
			 if (choice == 'y')
			 {
				 life1=1;
				 score1=0;
				 play=true;
			 }
			 else
				 if (choice == 'n')
				 {
				     play=false;
				 }
		}

		if (score1 == 550)                                                           //This will tell whether player has won or not.
		{
			flag2=true;                            
		}
		else 
			if (score1 < 550)
			{
				flag2=false;
			}
		

  } // Second Loop closing braket.

    system("cls");
		     
		if (play == false && flag3 == false)
	    {
			  cout << endl << endl << endl;
			  cout << " \t\t\t\t\t\t You Exited the Game !" << endl;
		}
		else 
			if (play == false && flag2 == false || life1 == 0)
		{
			  cout << endl << endl << endl;
              cout << "\t\t\t\t\t You lost the Game ! Better Luck next time." << endl;
		}
		else 
			if (play == false && flag2 == true && life1!=0)
		    {
			  cout << endl << endl << endl;
			  cout << " \t\t\t\t\t\t You won the Game !" << endl;
			}

cout << endl << endl << endl;

			storeScore(score1);                         // This calls the function to save the score.
			displaymax(score2);                         // This calls the function to display highest scores.

  cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
}

   system("pause");
   return 0;

} // Int main ending braket.