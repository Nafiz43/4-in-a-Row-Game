#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int column = 7;
int row = 6;
int human = 1;
int ai = 2;
int depth = 5;
int total_turn = 0;
vector<vector<int>> board((int)row, vector<int> ((int)column, 0));
vector<vector<int> > copy_board(vector<vector<int> > b)
   {
      vector<vector<int>> new_board(row, vector<int>(column));
      for (int r = 0; r < row; r++)
      {
         for (int c = 0; c < column; c++)
         {
            new_board[r][c] = b[r][c];
         }
      }
      return new_board;
   }
   void print_board(vector<vector<int> > &b)
   {
      cout<<"               ";
      cout<< "|---------------------------|" << endl;
      cout<<"                 ";
      for (int i = 0; i < column; i++)
      {
         cout<<i<<"   ";
      }
      cout<<endl;
      cout<<"               ";
      cout<< "|---------------------------|" << endl;
      for (int r = 0; r < row; r++)
      {
         cout<<"               ";
         for (int c = 0; c < column; c++)
         {
            cout << "|";
            if (b[row - r - 1][c]==0)
            {
               cout << "   ";
            }
            else if(b[row - r - 1][c]==1)
            {
               cout << " O ";
            }
            else if(b[row - r - 1][c]==2)
            {
               cout << " X ";
            }
            if (c + 1 == column)
            {
               cout << "|";
            }
         }
         cout << endl;
      }
      cout<<"               ";
      cout<< "|---------------------------|" << endl;
      cout << endl;
   }
class Human_Agent
{
public:
   int move;
   Human_Agent()
   {
      move=-1;
   }
   int human_move()
   {
      while (1)
      {
         cout << "           Enter a column number between [0-6]:     ";
         cin >> move;
         if (!(move < column && move >= 0))
         {
            cout<<"          Enter a valid column number!!           "<<endl;
         }
         else if (board[row - 1][move] != 0)
         {
            cout<<"          This column is full! Try another..        "<<endl;
         }
         else
         {
            break;
         }
         cout << endl << endl;
      }
      return move;
   }

};
bool goal_test(vector<vector<int> > &b, int p)
{
   int consecutive = 0;
   for (int c = 0; c < column - 3; c++)
   {
      for (int r = 0; r < row; r++)
      {
         for (int i = 0; i < 4; i++)
         {
            if (b[r][c + i] == p)
            {
               consecutive++;
            }
            if (consecutive == 4)
            {
               return true;
            }
         }
         consecutive = 0;
      }
   }
   for (int c = 0; c < column; c++)
   {
      for (int r = 0; r < row - 3; r++)
      {
         for (int i = 0; i < 4; i++)
         {
            if (b[r + i][c] == p)
            {
               consecutive++;
            }
            if (consecutive == 4)
               {
                  return true;
               }
         }
         consecutive = 0;
      }
   }
   for (int c = 0; c < column - 3; c++)
   {
      for (int r = 3; r < row; r++)
      {
         for (int i = 0; i < 4; i++)
         {
            if (b[r - i][c + i] == p)
            {
               consecutive++;
            }
            if (consecutive == 4)
               {
                  return true;
               }
         }
         consecutive = 0;
      }
   }
   for (int c = 0; c < column - 3; c++)
   {
      for (int r = 0; r < row - 3; r++)
      {
         for (int i = 0; i < 4; i++)
         {
            if (b[r + i][c + i] == p)
            {
               consecutive++;
            }
            if (consecutive == 4)
               {
                  return true;
               }
         }
         consecutive = 0;
      }
   }
   return false;
}
class AI_agent
{
public:
   AI_agent()
   {
       cout << "Move From Alpha Beta Agent:    " << endl;
   }
int ai_move()
{
   int v=Max(board, depth, 0 - INT_MAX, INT_MAX)[1];
   return v;
}
 void make_move(vector<vector<int> >& b, int c, int p)
   {
      for (int r = 0; r < row; r++)
      {
         if (b[r][c] == 0)
         {
            b[r][c] = p;
            break;
         }
      }
   }
array<int, 2> Max(vector<vector<int> > &b, int d, int alpha, int beta)
{
   if (d == 0 || d >= (column * row) - total_turn)
   {
      return array<int, 2>{evaluation(b), -1};
   }
    array<int, 2> best_move = {INT_MIN, -1};

      if (goal_test(b, human))
      {
         return best_move;
      }
      for (int c = 0; c < column; c++)
      {
         if (b[row - 1][c] == 0)
         {
            vector<vector<int> > new_board = copy_board(b);
            make_move(new_board, c, ai);
            int score = Min(new_board, d - 1, alpha, beta)[0];
            if (score > best_move[0])
            {
               best_move = {score, c};
            }
            alpha = max(alpha, best_move[0]);
            if (alpha >= beta)
            {
               break;
            }
         }
      }
       return best_move;
}
array<int, 2> Min(vector<vector<int> > &b, int d, int alpha, int beta)
{
   //cout<<"calling Min"<<endl;
   if (d == 0 || d >= (column * row) - total_turn)
   {
     return array<int, 2>{evaluation(b), -1};
   }
    array<int, 2> best_move = {INT_MAX, -1};
      if (goal_test(b, ai))
      {
         return best_move;
      }
      for (int c = 0; c < column; c++)
      {
         if (b[row - 1][c] == 0)
         {
            vector<vector<int> > new_board = copy_board(b);
            make_move(new_board, c, human);
            int score = Max(new_board, d - 1, alpha, beta)[0];
            if (score < best_move[0])
            {
               best_move = {score, c};
            }
            beta = min(beta, best_move[0]);
            if (alpha >= beta)
            {
               break;
            }
         }
      }
      return best_move;
}

int evaluation(vector<vector<int>> b)
{

   int p=1;
   int score = 0;
   vector<int> row_list(column);
   vector<int> column_list(row);
   vector<int> set(4);
   for (int r = 0; r < row; r++)
   {
      for (int c = 0; c < column; c++)
      {
         row_list[c] = b[r][c];
      }
      for (int c = 0; c < column - 3; c++)
      {
         for (int i = 0; i < 4; i++)
         {
            set[i] = row_list[c + i];
         }
         score += set_score(set);
      }
   }
   for (int c = 0; c < column; c++)
   {
      for (int r = 0; r < row; r++)
      {
         column_list[r] = b[r][c];
      }
      for (int r = 0; r < row - 3; r++)
      {
         for (int i = 0; i < 4; i++)
         {
            set[i] = column_list[r + i];
         }
         score += set_score(set);
      }
   }
   for (int r = 0; r < row - 3; r++)
   {

      for (int c = 0; c < column - 3; c++)
      {
         for (int i = 0; i < 4; i++)
         {
            set[i] = b[r + i][c + i];
         }
         score += set_score(set);
      }
   }
   for (int r = 0; r < row - 3; r++)
   {
      for (int c = 0; c < column - 3; c++)
      {
         for (int i = 0; i < 4; i++)
         {
            set[i] = b[r + 3 - i][c + i];
         }
         score += set_score(set);
      }
   }
   return score;
}
int set_score(vector<int> v)
{
   int score=0;
   int a = 0;
   int h = 0;
   int e = 0;
   for (int i = 0; i < v.size(); i++)
   {
        if (v[i]==ai)
        {
         a=a+1;
        }
        else if(v[i]==human)
        {
         h=h+1;
        }
        else if(v[i]==0)
        {
         e=e+1;
        }
   }
   if(a==4)
   {
         score=100000;
   }
   else if(a==3 && e==1)
   {
      score=1000;
   }
   else if(a==2 && e==2)
   {
      score=100;
   }
   else if(a==1 && e==3)
   {
      score=10;
   }
   else if(e==4)
   {
      score=5;
   }
   else if(h==4)
   {
      score=-100000;
   }
   else if(h==3 && e==1)
   {
      score=-1000;
   }
   else if(h==2 && e==2)
   {
      score=-100;
   }
    else if(h==1 && e==3)
   {
      score=-10;
   }
   return score;
}
};
class Four_in_a_row
{
public:
   bool game_end;
   int currently_playing;
   Four_in_a_row()
   {
      cout<<"**********************!!!GAME STARTS!!!!!**********************"<<endl;
      game_end = false;
      currently_playing= human;
   }
   void make_move(vector<vector<int> >& b, int c, int p)
   {
      for (int r = 0; r < row; r++)
      {
         if (b[r][c] == 0)
         {
            b[r][c] = p;
            break;
         }
      }
   }
   void play_game()
   {
   print_board(board);
   while (!game_end)
   {
      if (currently_playing == ai)
      {
         AI_agent a;
         make_move(board, a.ai_move(), ai);
      }
      else if (currently_playing == human)
      {
         Human_Agent ha;
         make_move(board, ha.human_move(), human);
      }
      else if (total_turn == row * column)
      {
         game_end = true;
      }
      game_end = goal_test(board, currently_playing);
      if (currently_playing==human)
      {
         currently_playing=ai;
      }
      else
      {
         currently_playing=human;
      }
      total_turn++;
      cout << endl;
      print_board(board);
   }
      if (total_turn == row * column)
      {
         cout<<"*****************!!!DRAW!!!*******************"<<endl;
      }
      else
      {
         if (currently_playing==human)
         {
            cout<<"*****************!!!AI WINS THE MATCH!!!*******************"<<endl;
         }
         else
         {
            cout<<"*****************!!!YOU WIN THE MATCH!!!*******************"<<endl;
         }
      }
   }
   ~Four_in_a_row()
   {
      cout<<"**********************!!!GAME ENDS!!!**********************"<<endl;
   }

};
int main()
{
   Four_in_a_row p;
   p.play_game();
}
