#include <bits/stdc++.h>
#include <string>
#include <iostream>
using namespace std;

void encryptData(string& s, int key){
    for(int i=0; i<s.length(); i++)
        s[i]+=key;
}

void decryptData(string& s, int key){
    for(int i=0; i<s.length(); i++)
        s[i]-=key;
}

class owner{
    string ownerName,address, mobile, password, value;
    int algoKey;
    public:
    setValue(string ownerval, string add, string mob, string pwd, int key){
        ownerName=ownerval;
        address=add;
        mobile=mob;
        password=pwd;
        algoKey=key;
        cout<<"\n\tPlease store your Key credentials in a safe manner: "<< key<<"\n";
    };
    getValue(){
        cout<<ownerName<<" "<<address<<" "<<mobile<<" "<<password<<" "<<value;
    }
};

class node{
    owner data;
    int nodeNumber;
    string  nodeId, pid, cid;

    public:
    string setValueNode(owner newOwner, string& p, int& n){
        data=newOwner;
        nodeNumber=n;
        nodeId=p+char(rand()%26+41);
        pid=p;
        cid="";
        return nodeId;
    }
    getValue(){
        data.getValue();
        cout<<nodeNumber<<" "<<nodeId<<" "<<pid<<" "<<cid;
    }

    updateChild(string c){
        cid=c;
    }
};

map<string, node> m;


string pd;
owner getUserDetails(){
    owner newNode;
    string ownerName,address, mobile, pwd, value;
    cout<<"enter owner name:\t";
    cin>>ownerName;
    cout<<"enter address:\t";
    cin>>address;
    cout<<"enter mobile:\t";
    cin>>mobile;
    cout<<"enter password:\t";
    cin>>pwd;
    int key=rand()%26+1;
    encryptData(ownerName,key);
    encryptData(address,key);
    encryptData(mobile,key);
    encryptData(pwd,key);
    newNode.setValue(ownerName, address, mobile, pwd, key);
    //newNode.getValue();
    return newNode;

}

owner userCreation(){
    cout<<"enter the new user details\n";
    owner newNode=getUserDetails();
    return newNode;
}

string nodeCreation(owner newOwner, int cnt){
    node newNode;
    string p;
    cout<<"enter parent ID:\t";
    cin>>p;
    string nodeId=newNode.setValueNode(newOwner, p, cnt);
    m[nodeId]=newNode;
    m[p].updateChild(nodeId);
    newNode.getValue();
    return nodeId;
}
int main(){
    int cnt=0, nodeId, pwd, algoKey,i;

    cin>>i;
    switch(i){
        case 1: owner newNode=userCreation();
            string pid=nodeCreation(newNode, ++cnt);

        break;
    }
    return 0;
}
