#include<iostream>
#include<string>
using namespace std;
int main()
{
    string a,b;
    short ai=0,bi=0,as=0,bs=0;//ai,bi->small Number dot，sa,bs-> small Number
    cin >> a;
    cin >> b;
    for(;a[ai]!='.'&&(ai<a.size());ai++);
    for(;b[bi]!='.'&&(bi<b.size());bi++);
    for(;(ai+as)<a.size();as++);
    for(;(bi+bs)<b.size();bs++);
    unsigned short C=0,K=1;
//========Small Number========================
    if(as>=bs)
    {
        for(;!((ai+bs-K)<=ai)&&!((bi+bs-K)<=bi);K++)
        {
            C=((unsigned short)a[ai+bs-K]-48)+((unsigned short)b[bi+bs-K]-48)+(C/7);
            a[ai+bs-K]=(char)((C%7)+48);
        }
        char S='F';short G=0;
        for(K=1;((ai+K)<a.size());K++)
        {
            if(S=='T'&&a[ai+K]=='0'){continue;}
            if(S=='F'&&a[ai+K]=='0')
                {S='T';G=ai+K;}
            else if(a[ai+K]!=0)
                {S='F';G=0;}
        }
        if(S=='T'&&ai==G-1)
            G=ai;
        if(S=='T')
            for(;G<a.size();G++)
                a[G]='\0';
        else if(G>0)
            for(G=G+1;G<a.size();G++)
                a[G]='\0';
    }
    else if(as<bs)
    {
        for(;!((ai+as-K)<=ai)&&!((bi+as-K)<=bi);K++)
        {
            C=((unsigned short)a[ai+as-K]-48)+((unsigned short)b[bi+as-K]-48)+(C/7);
            b[bi+as-K]=(char)((C%7)+48);
        }
                char S='F';short G=0;
        for(K=1;((bi+K)<b.size());K++)
        {
            if(S=='T'&&b[bi+K]=='0'){continue;}
            if(S=='F'&&b[bi+K]=='0')
                {S='T';G=bi+K;}
            else if(b[bi+K]!=0)
                {S='F';G=0;}
        }
        if(S=='T'&&bi==G-1)
            G=bi;
        if(S=='T')
            for(;G<b.size();G++)
                b[G]='\0';
        else if(G>0)
            for(G=G+1;G<b.size();G++)
                b[G]='\0';
    }
//=============All Number========================
    if(bi<=ai)//a>=b
    {
        for(K=1;(bi-K)>=0;K++)
        {
            C=((unsigned short)a[ai-K]-48)+((unsigned short)b[bi-K]-48)+(C/7);
            a[ai-K]=(char)((C%7)+48);
        }
        if((C/7)!=0)
        {
            for(;(ai-K)>=0;K++)
            {
            C=((unsigned short)a[ai-K]-48)+(C/7);
            a[ai-K]=(char)((C%7)+48);
            }
        }
        if(C/7!=0)
            cout << (char)(C/7+48);
        for(K=0;K<ai;K++)
            cout << a[K];
    }
    else if(bi>ai)//b>a
    {
        for(K=1;(ai-K)>=0;K++)
        {
            C=((unsigned short)a[ai-K]-48)+((unsigned short)b[bi-K]-48)+(C/7);
            b[bi-K]=(char)((C%7)+48);
        }
        if((C/7)!=0)
        {
            for(;(bi-K)>=0;K++)
            {
            C=((unsigned short)b[bi-K]-48)+(C/7);
            b[bi-K]=(char)((C%7)+48);
            }
        }
        if(C/7!=0)
            cout << (char)(C/7+48);
        for(K=0;K<bi;K++)
            cout << b[K];
    }
    if(as>=bs)
    {
        for(K=ai;K<a.size();K++)
            cout << a[K];
    }
    else if(as<bs)
    {
        for(K=bi;K<b.size();K++)
            cout << b[K];
    }
}
