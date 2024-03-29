﻿#include "graphics.h"
#define H 750
#define L 1000
#define RC (H+L)/60


struct jeu{
    int tab[3][3]; //0: pas de pion, 1: pion J1; 2: pion J2
    int aqui; // 1: J1 joue; 2: J2 joue
};
typedef struct jeu JEU;

POINT ij2point(int i, int j) //prend en entre i et j, et renvoie le centre du cercle correspondant
{
     POINT m;
     m.x=(0.2*L)+(0.3*L*i);
     m.y=(0.2*H)+(0.3*H*j);
     return m;
}



void affichage(int i, int j,int n) //prend i et j en facteur et trace un cercle correspondant au coordonees.
{
   POINT m=ij2point(i,j);
   if (n == 1)
   {
    draw_fill_circle(m,RC-1,blue);
   }
   else     
   if (n == 2)
   {
    draw_fill_circle(m,RC-1,rouge);
   }
   else 
   {
    draw_fill_circle(m,RC-1,noir);
   }
}

POINT coord()  //attend un clic et renvoie i et j codes dans un point et renvoie (-1,-1) si il clic nul part
{
      POINT p=wait_clic();
      POINT m;
      int i,j,z;
      i=-1; j=-1;
      for ( z = 0; z < 3; z++)
      {
         if ( (p.x > (0.2*L+0.3*L*z)-(RC/2)) && (p.x < (0.2*L+0.3*L*z)+(RC/2)) ) 
        {
            i=z;
        } 
        
      }
      for (z = 0; z < 3; z++)
      {
        if (p.y > (0.2*H+0.3*H*z)-(RC/2) && p.y < (0.2*H+0.3*H*z)+(RC/2))
         {
            j=z ;
         } 
       }
      
      m.x = i;
      m.y = j;
      return m;
}

int victoire(int tab[3][3])// verifie si un des joueurs à gagner.
{
      if (tab[0][0] == tab[0][1] && tab[0][2] == tab[0][1] && tab[0][0] != 0)
      {
        printf("JOUEUR %d(%s) GAGNE", tab[0][0], (tab[0][0] == 1) ? "Bleu" : "Rouge");
        fflush(stdout);
        return 1;
      }
      else if (tab[0][0] == tab[1][0] && tab[2][0] == tab[1][0] && tab[0][0] != 0)
      {
        printf("JOUEUR %d(%s) GAGNE", tab[0][0], (tab[0][0] == 1) ? "Bleu" : "Rouge");
        fflush(stdout);
        return 1;
      }
      else if (tab[2][0] == tab[2][1] && tab[2][2] == 2 && tab[2][0] !=0)
      {
        printf("JOUEUR %d(%s) GAGNE", tab[2][0], (tab[2][0] == 1) ? "Bleu" : "Rouge");
        fflush(stdout);
        return 1;
      }
      else if (tab[0][2] == tab[1][2] && tab[2][2] == tab[1][2] && tab[0][2] != 0)
      {
        printf("JOUEUR %d(%s) GAGNE", tab[0][2], (tab[0][2] == 1) ? "Bleu" : "Rouge");
        fflush(stdout);
        return 1;
      }
      else if (tab[0][0] == tab[1][1] && tab[2][2] == tab[1][1] && tab[0][0] != 0)
      {
        printf("JOUEUR %d(%s) GAGNE", tab[0][0], (tab[0][0] == 1) ? "Bleu" : "Rouge");
        fflush(stdout);
        return 1;
      }
      else if (tab[2][0] == tab[1][1] && tab[1][1] == tab[0][2] && tab[2][0] != 0)
      {
        printf("JOUEUR %d(%s) GAGNE", tab[2][0], (tab[2][0] == 1) ? "Bleu" : "Rouge");
        fflush(stdout);
        return 1;
      }
      else if (tab[1][0] == tab [1][1] && tab[1][1] == tab[1][2] && tab[1][0] != 0)
      {
        printf("JOUEUR %d(%s) GAGNE", tab[1][0], (tab[1][0] == 1) ? "Bleu" : "Rouge");
        fflush(stdout);
        return 1;
      }
     
      else if (tab[0][1] == tab[1][1] && tab[2][1] == tab[0][1] && tab[0][1] != 0)
      {
        printf("JOUEUR %d(%s) GAGNE", tab[0][1], (tab[0][1] == 1) ? "Bleu" : "Rouge");
        fflush(stdout);
        return 1;
      }
      
        return 0;
}

int possible(POINT p, int tab[3][3])// verifie si le jeton est possible d'être deplacer. renvoie 1 si oui sinon renvoie 0
{
    
    if (p.x == p.y && p.x == 0)
    {
        if ((tab[p.x + 1][p.y] == 0) || (tab[p.x + 1][p.y + 1] == 0) || (tab[p.x][p.y + 1] == 0))
                return 1;
        else
                return 0;
    }
    if (p.x == 1 && p.y == 0)
    {
        if ((tab[p.x + 1][p.y] == 0) || (tab[p.x - 1][p.y] == 0) || (tab[p.x][p.y + 1] == 0))
                return 1;
        else
                return 0;
    }
    if (p.x == 2 && p.y == 0)
    {
        if ((tab[p.x - 1][p.y] == 0) || (tab[p.x - 1][p.y + 1] == 0) || (tab[p.x][p.y + 1] == 0))
                return 1;
        else
                return 0;
    }
    if (p.x == 0 && p.y == 1)
    {
        if ((tab[p.x + 1][p.y] == 0) || (tab[p.x][p.y - 1] == 0) || (tab[p.x][p.y + 1] == 0))
                return 1;
        else
                return 0;
    }
    if (p.x == 1 && p.y ==1)
    {
        return 1;
    }
    if (p.x == 2 && p.y == 1)
    {
        if ((tab[p.x - 1][p.y] == 0) || (tab[p.x][p.y - 1] == 0) || (tab[p.x][p.y + 1] == 0))
                return 1;
        else
                return 0;
    }
    if (p.x == 0 && p.y == 2)
    {
        if ((tab[p.x + 1][p.y] == 0) || (tab[p.x][p.y - 1] == 0) || (tab[p.x + 1][p.y - 1] == 0))
                return 1;
        else
                return 0;
    }
    if (p.x == 1 && p.y == 2)
    {
        if ((tab[p.x - 1][p.y] == 0) || (tab[p.x][p.y - 1] == 0) || (tab[p.x + 1][p.y] == 0))
                return 1;
        else
                return 0;
    }
    if (p.x == 2 && p.y == 2)
    {
        if ((tab[p.x - 1][p.y] == 0) || (tab[p.x - 1][p.y - 1] == 0) || (tab[p.x][p.y - 1] == 0))
                return 1;
        else
                return 0;
    }
       
    return -1;
}

int deplacement(POINT p1,POINT p2,int ta, int tab[3][3])// prend en entrer les deux points desirés et fait apparaitre un jeton au deuxieme point en supprimant le jeton present au premier point.
{                                                       //renvoie 0 pour comfirmer le deplacement sinon 1.
    if (tab[p2.x][p2.y] == 0)
    {
        affichage(p2.x, p2.y, ta);
        tab[p2.x][p2.y] = ta;
        tab[p1.x][p1.y] = 0;
        affichage(p1.x, p1.y, 0);
        return 0;
    }
    return 1;
}
int verife_deplacement(POINT p1, POINT p2, int tab[3][3])// empêche les deplacments impossibles qui ne suivent pas les lignes du plateau
{
    if (p1.x == 0 && p1.y == 0)
    {
        if ((p2.x == 1 && p2.y == 0) || (p2.x == 0 && p2.y == 1) || (p2.x == 1 && p2.y == 1))
        {
            return 1;
        }
        else    
            return 0;
    }
    else   
            if (p1.x == 1 && p1.y == 0)
            {
                if ((p2.x == 0 && p2.y == 0) || (p2.x == 2 && p2.y == 0) || (p2.x == 1 && p2.y == 1))
                {
                    return 1;
                }
                else    
                    return 0;
            }
            else    
            if (p1.x == 2 && p1.y == 0)
            {
                if ((p2.x == 1 && p2.y == 0) || (p2.x == 2 && p2.y == 1) || (p2.x == 1 && p2.y == 1))
                {
                    return 1;
                }
                else    
                    return 0;
            }
            else    
            if (p1.x == 0 && p1.y == 1)
            {
                if ((p2.x == 0 && p2.y == 0) || (p2.x == 0 && p2.y == 2) || (p2.x == 1 && p2.y == 1))
                {
                    return 1;
                }
                else
                    return 0;
            }
            else    
            if (p1.x == 1 && p1.y == 1)
            {   
                    return 1;
            }
            else 
            if (p1.x == 2 && p1.y == 1)
            {
                if ((p2.x == 2 && p2.y == 2) || (p2.x == 2 && p2.y == 0) || (p2.x == 1 && p2.y == 1))
                {
                    return 1;
                }
                else
                    return 0;
            }
            else 
            if (p1.x == 0 && p1.y == 2)
            {
                if ((p2.x == 0 && p2.y == 1) || (p2.x == 1 && p2.y == 2) || (p2.x == 1 && p2.y == 1))
                {
                    return 1;
                }
                else
                    return 0;
            }
            else 
            if (p1.x == 1 && p1.y == 2)
            {
                if ((p2.x == 0 && p2.y == 2) || (p2.x == 2 && p2.y == 2) || (p2.x == 1 && p2.y == 1))
                {
                    return 1;
                }
                else
                    return 0;
            }
            else 
            if (p1.x == 2 && p1.y == 2)
            {
                if ((p2.x == 1 && p2.y == 2) || (p2.x == 2 && p2.y == 1) || (p2.x == 1 && p2.y == 1))
                {
                    return 1;
                }
                else
                    return 0;
            }
            else    
                    return 0;
}
int main( int argc, char *argv[] )
{
    
        init_graphics(L,H,"Plateau");

        JEU tmq;
        POINT a,b,c,d,e,f,g,h,v;
        POINT p,p1,p2;
        int i,j,u,z,k,t;

        a=ij2point(0,0);
        b=ij2point(0,1);
        c=ij2point(0,2);
        d=ij2point(1,0);
        e=ij2point(1,1);
        f=ij2point(1,2);
        g=ij2point(2,0);
        h=ij2point(2,1);
        v=ij2point(2,2);

        plateau(a,b,c,d,e,f,g,h,v);
    
    for (i = 0; i < 3; i++) // initialise le tableau
    
    {
       for (j = 0; j < 3; j++)
        {
           tmq.tab[i][j] = 0;
        }
        
    }
    tmq.aqui = 1;
    for(u = 0;u < 6;u++)
    {
        k = 0;
        while (k == 0)  
        {
            p = coord();
            if (tmq.tab[p.x][p.y] == 0)
            {
                affichage(p.x,p.y,tmq.aqui);
                tmq.tab[p.x][p.y] = tmq.aqui;
                k = 1;
            }
        }       
        if (tmq.aqui == 1)
           tmq.aqui = 2 ;
        else  
           tmq.aqui = 1;
           
        if (victoire(tmq.tab) == 1)
            exit(0);
        k = 0;
    }
    
   
    for (i = 0; i < 3; i++)
    {
       for (j = 0; j < 3; j++)
        {
           printf("la case [%d][%d] a la valeure %d    ",i,j,tmq.tab[i][j]    );// affiche les valeures du tableau.
           fflush(stdout);
        }
        
    }
    
    
    while(1)
    {
        z = 0;
        if (tmq.aqui == 1)
        {
            while(z == 0)
            {
                p1 = coord();
                if (tmq.tab[p1.x][p1.y] == 1)
                {
                    k = possible(p1, tmq.tab);
                    if (k == 1)
                    z = 1 ;
                }  
            }
            while(z == 1)
            {
                t = 0;
                while(t == 0)
                {
                    p2 = coord();
                    t = verife_deplacement(p1,p2,tmq.tab);
                }
                z = deplacement(p1,p2,tmq.aqui,tmq.tab);
            }
        }
        else    
        {
           while(z == 0)
            {
                p1 = coord();
                if (tmq.tab[p1.x][p1.y] == 2)
                {
                    k = possible(p1, tmq.tab);
                    if (k == 1)
                    z = 1 ;
                } 
            }
            while(z == 1)
            {
                t = 0;
                while(t == 0)
                {
                    p2 = coord();
                    t = verife_deplacement(p1,p2,tmq.tab);
                }
                z = deplacement(p1,p2,tmq.aqui,tmq.tab);    
            }
        }
        
        if (tmq.aqui == 1)
            tmq.aqui = 2;
        else
            tmq.aqui = 1;
            
        if (victoire(tmq.tab) == 1)
            exit(0);
    }
    
    wait_escape();
	exit(0);
}