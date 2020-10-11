#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cmath>

using namespace std;

int main(int argc,char *argv[]){
   fstream fs(argv[1]);
   stringstream ss;
   ss<<fs.rdbuf();
   string str=ss.str();
   for(int i=0;i<str.length();){
       if(str[i]==' '||str[i]=='\n'){i++;}
       else if (str[i]==':')
       {    
           if(str[i+1]!='='){
                cout<<"Colon"<<endl;
                i++;
           }else
           {
               cout<<"Assign"<<endl;
               i+=2;
           }
           
       }else if (str[i]=='+')
       {
           cout<<"Plus"<<endl;
           i++;
       }else if (str[i]=='*')
       {
           cout<<"Star"<<endl;
           i++;
       }else if (str[i]==',')
       {
           cout<<"Comma"<<endl;
           i++;
       }else if (str[i]=='(')
       {
           cout<<"LParenthesis"<<endl;
           i++;
       }else if (str[i]==')')
       {
           cout<<"RParenthesis"<<endl;
           i++;
       }else if(str[i]=='B'){
           if(str.substr(i,5)=="BEGIN"){
               cout<<"Begin"<<endl;
               i+=5;
           }
       }else if (str[i]=='E')
       {
           if(str.substr(i,3)=="END"){
               cout<<"End"<<endl;
               i+=3;
           }else if(str.substr(i,4)=="ELSE"){
               cout<<"Else"<<endl;
               i+=4;
           }
       }else if (str[i]=='F')
       {
           if(str.substr(i,3)=="FOR"){
               cout<<"For"<<endl;
               i+=3;
           }
       }else if (str[i]=='I')
       {
           if(str.substr(i,2)=="IF"){
               cout<<"If"<<endl;
               i+=2;
           }
       }else if (str[i]=='T')
       {
           if(str.substr(i,4)=="THEN"){
               cout<<"Then"<<endl;
               i+=4;
           }
       }else if(isdigit(str[i])||isalpha(str[i])){
           string tmp=str.substr(i,1);
           int j=1;
           while(isdigit(str[i+j])||isalpha(str[i+j])){
               tmp+=str[i+j];
               j++;
            }
            if(isdigit(tmp[0])){
                int ii=1;
                while (isdigit(tmp[ii])){
                    ii++;
                }
                string ttmp=tmp.substr(0,ii);
                while(ttmp[0]=='0'&&ttmp.length()>=2){ttmp.erase(0,1);}
                cout<<"Int("<<ttmp<<")"<<endl;
                if(ii!=tmp.length()){
                    cout<<"Ident("<<tmp.substr(ii)<<")"<<endl;
                }
            }else{
                cout<<"Ident("<<tmp<<")"<<endl;
            }
           i+=j;
       }else{
           cout<<"Unknown"<<endl;
           break;
       }
 
   }
   system("pause");
   return 0;

}
