//
//  main.cpp
//  公主与青蛙王子
//
//  Created by 杨博文 on 2024/4/17.
//

#include <iostream>
using namespace std;

class FairyTale
{public:
    void act1()
    {  cout<<"Princess meets Frog" << endl;
       act2();
    }
    void act2()
    {  cout<<"Princess kisses Frog"<<endl;
       act3();
    }
    virtual void act3()
    {  cout<<"Frog turns into Prince"<<endl;
       act4();
    }
    void act4()
    {  cout<<"They lives happily ever after" <<endl;
       act5();
    }
    void act5()
    {  cout<<"The End"<<endl;
    }
    virtual ~FairyTale()
    {}
};

class UnhappyTale: public FairyTale
{public:
    void act3()
    { cout<<"Frog stays a frog"<<endl;
      act4();
    }
    void act4()
    { cout<<"Princess runs away in disgust"<<endl;
      act5();
    }
    void act5()
    {  cout<<"not so happy end"<<endl;
    }
    virtual ~UnhappyTale()
    {}
};

int main(int argc, const char * argv[]) {
    FairyTale* tale;
    char c;
    cout<<"Which tale would you like to hear(f/u?)";
    cin>>c;
    if(c=='f')
       tale = new FairyTale;
    else
       tale = new UnhappyTale;
    tale->act1();
    delete tale;
    return 0;
}
