            /***********************/
            /**  MD. Rezaul karim **/
            /**  roll : 1407055   **/
            /***********************/

#include <bits/stdc++.h>
using namespace std;


class Attendence{
    float a,b;
public:
    Attendence(){
        a = 40,b = 50;
    }
    Attendence(float a,float b):a(a),b(b){}
    float small(float x){
        float crispRange = a - 10;
        float value;
        if(x>=0 && x<crispRange){
            value = 1.0;
        }else if(x>=crispRange && x<=b){
            value = (b-x)/(b-crispRange);
        }else{
            value = 0.0;
        }
        return value;
    }

    float large(float x){
        float crispRange = b + 10;
        float value;
        if(x>=crispRange){
            value = 1.0;
        }else if(x<crispRange && x>=a){
            value = (x-a)/(crispRange-a);
        }else{
            value = 0.0;
        }
        return value;
    }
};

class PresentTime{
    // Fuzzy ranges
    float a,b,c,d;

public:
    PresentTime(){
        a = 30;
        b = 40;
        c = 60;
        d = 70;
    }
    PresentTime(float a,float b,float c,float d):a(a),b(b),c(c),d(d){}

    float inadequate(float x){
        float crispRange = a - 10;
        float value;
        if(x>=0 && x<crispRange){
            value = 1.0;
        }else if(x>=crispRange && x<=b){
            value = (b-x)/(b-crispRange);
        }else{
            value = 0.0;
        }
        return value;
    }
    float marginal(float x){
        float value;
        float mid = (d-a)/2;
        if(x>=a && x<=mid ){
            value = (x-a)/(mid-a);
        }else if(x>mid && x<=d){
            value =  (d-x)/(d-mid);
        }else{
            value = 0.0;
        }
        return value;
    }
    float adequate(float x){
        float crispRange = d + 10;
        float value;
        if(x>=crispRange){
            value = 1.0;
        }else if(x>=c && x<crispRange){
            value = (x-c)/(crispRange-c);
        }else{
            value = 0.0;
        }
        return value;
    }

};

class FuzzyMark{
    float a,b,c,d;
    PresentTime pTime;
    Attendence attndnce;

public:
    FuzzyMark(){
        a = 25;
        b = 30;
        c = 55;
        d = 60;
    }

    /*******************************************************/
    /**                                                    */
    /**         ===< Mark Distribution Table >===          */
    /**                                                    */
    /**          \  |InAdequate| Marginal | Adequate       */
    /**     --------+----------+----------+---------       */
    /**      Small  |   LOW    |   LOW    |   AVG          */
    /**     --------+----------+----------+---------       */
    /**      Large  |   LOW    |   AVG    |   HIGH         */
    /**     --------+----------+----------+---------       */
    /**                                                    */
    /*******************************************************/

    FuzzyMark(float a,float b,float c,float d):a(a),b(b),c(c),d(d){}

    float low(float x,float y){
        float value1,value2,value3;

        /// Here Low belongs to Three cell in the table shown in top ^
        value1 = max(attndnce.small(x),pTime.inadequate(y));
        value2 = max(attndnce.small(x),pTime.marginal(y));
        value3 = max(attndnce.large(x),pTime.inadequate(y));

        /// return the average value :)
        return (value1+value2+value3)/3;
    }

    float average(float x,float y){
         float value1,value2;

         /// Here AVG belongs to Two cell in the table shown in top ^
        value1 = max(attndnce.small(x),pTime.adequate(y));
        value2 = max(attndnce.large(x),pTime.marginal(y));

        /// return the average value :)
        return (value1+value2)/2;
    }

    float high(float x,float y){
        float value1;

        /// Here HIGH belongs to One cell in the table shown in top ^
        value1 = max(attndnce.large(x),pTime.adequate(y));

        /// return the value :)
        return value1;
    }

public:
    float calculateTheMark(float attn,float ttme){
        float MARKS = 0;
        int cnt1=0,cnt2=0,cnt3=0;

        for(int i = 0; i<= 100 ;i+=10 ){
            if(i>=0 && i<=a){
                MARKS+= (low(attn,ttme)*i);
                cnt1++;
            }else if(i>a && i<=b){
                MARKS+= (average(attn,ttme)*i);
                cnt2++;
            }else{
                MARKS+= (high(attn,ttme)*i);
                cnt3++;
            }
        }

       // cout<<MARKS<<endl;

        MARKS /= (low(attn,ttme)*cnt1 + average(attn,ttme)*cnt2 + high(attn,ttme)*cnt3);
        return MARKS;

    }
};

int main()
{
    float attndnce,tme,mrks;
    cout<<"Attendance (%) : ";
    cin>>attndnce;
    cout<<"Total time present in class (%) : ";
    cin>>tme;

    FuzzyMark marks;
    mrks = marks.calculateTheMark(attndnce,tme);

    cout<<"Marks is : "<<mrks<<" %"<<endl;



    return 0;
}
