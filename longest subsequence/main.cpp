//
//  main.cpp
//  longest subsequence
//
//  Created by Vivek Tejwani on 27/02/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
using namespace std;
char A[100];
char B[100];
int c[100][100];
int b[100][100];

void LCS(int m,int n);
int main (int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    cout<<"Enter the value of m\n";
    int m;
    cin>>m;
    cout<<"Enter the value of n\n";
    int n;
    cin>>n;
    cout<<"Enter the first sequence\n";
    for(int i=0;i<m;i++)
    {
        cin>>A[i];
    }
    cout<<"Enter the second sequence\n";
    for(int i=0;i<n;i++)
    {
        cin>>B[i];
    }
        
    LCS(m,n);

        
    return 0;
}

void LCS(int m, int n)
{   
    cout<<"start\n";
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            b[i][j]=5;
            cout<<" "<<b[i][j];
        }
        cout<<"\n";
    }

    cout<<"LCS\n";
    for(int i=0;i<=m;i++)
    {
        c[i][0]=0;
    }
    cout<<"First row set to 0\n";
    for(int i=0;i<=n;i++)
    {
        c[0][i]=0;
    }
    cout<<"First column set to 0\n";
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(A[i-1]==B[j-1])
            {
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]=0;
            }
            else if(c[i-1][j]>=c[i][j-1])
            {
                c[i][j]=c[i-1][j];
                b[i][j]=1;
            }
            else
            {
                c[i][j]=c[i][j-1];
                b[i][j]=2;
            }
            cout<<" "<<c[i][j];
        }
        cout<<"\n";
    }
    cout<<"Finished c matrix\n";
    cout<<"I dont get the problem\n";
    int x=m;
    int y=n;
    int z=b[m][n];
    char ans[z];
    z=z-1;
    while(x>0)
    {
        while(y>0)
        {
            if(x<=0)
                break;
            else
            {
                if(b[x][y]==0)
                {
                    ans[z]=A[x-1];
                    z--;
                    x--;
                    y--;
                }
                else if(b[x][y]==1)
                {
                    x--;
                }
                else
                    y--;
            }
        }
    }
    cout<<"The subsequence is:\n";
    for(int i=0;i<b[m][n];i++)
    {
        cout<<" "<<ans[i];
    }

    return;
}