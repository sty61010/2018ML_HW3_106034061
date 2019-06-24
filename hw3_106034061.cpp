//
//  hw3_106034061.cpp
//  Program
//
//  Created by 曾靖渝 on 2018/10/19.
//  Copyright © 2018年 曾靖渝. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#define ETA 0.2
using namespace std;
using example=vector<int>;
class perception_learning//Perception Learning Classifier(Linear Seperabitlity)
{
private:
    set<example> Training_Set;
    vector<int> class_labels;
    vector<double> weight;//Memorize all of Weights
    int c_x=0;//c(x)
    int h_x=0;//h(x)
    int attribute_number;
    int instance_number;
    int modifying_number;//Memorize Modifying times
public:
    perception_learning(int attribute_number, int instance_number)//Initial all of varibles
    {
        this->attribute_number=attribute_number;
        this->instance_number=instance_number;
        modifying_number=0;
        for(int i=0;i<=attribute_number;i++)
        {
            weight.push_back(0.2);
        }
    }
    void add_to_TrainingSet(example ex)
    {
        Training_Set.insert(ex);
    }
    void print_TrainingSet(void)//For Debugging
    {
        cout<<"Training Set:"<<endl;
        for(auto ex:Training_Set)
        {

            for(auto i: ex)
                cout<<i;
            cout<<endl;
        }
    }
    void print_example(example ex)//Print out an Example for Debugging
    {
        cout<<"Example:";
        for(auto i:ex)
            cout<<i;
        cout<<endl;
    }
    void print_weight(void)//Print out all of Weight for Recording
    {
        cout<<"Weights:";
        for(auto w:weight)
            cout<<w<<" ";
        cout<<endl;
    }
    int compute_ClassLabel(example ex)//Compute c(x)
    {
        int count=0;
        for(auto i:ex)
            if(i==1)count++;
        if(count>3)c_x=1;
        else c_x=0;
        cout<<"c(x)="<<c_x<<endl;
        return c_x;
    }
    int compute_H_ClassLabel(example ex)//Compute h(x)
    {
        double sum=0;
        
        for(int i=0;i<=attribute_number;i++)
        {
            sum+=ex[i]*weight[i];
        }
        if(sum>0)h_x=1;
        else h_x=0;
        cout<<"h(x)="<<h_x<<endl;
        return h_x;
    }
    void Classifying(example ex)//Classifying
    {
//        cout<<"Attribute Number:"<<attribute_number<<" ,Instance Number:"<<instance_number<<endl;
        cout<<"->Classifying..........."<<endl;
        compute_H_ClassLabel(ex);
        compute_ClassLabel(ex);
        if(h_x!=c_x)modify_weight(ex);
        print_weight();
    }
    void modify_weight(example ex)//Refresh Weights
    {
        cout<<"->Modify Weight"<<endl;
        for(int i=0;i<=attribute_number;i++)
        {
            weight[i]+=ETA*(double)ex[i]*(double)(c_x-h_x);
        }
        modifying_number++;
    }
    void print_Modifying_Number(void)
    {
        cout<<"->Modify:"<<modifying_number<<" times"<<endl;
    }
};

int main(void)
{
    int attribute_number=25;
//    cin>>attribute_number;
    int instance_number=20;
//    cin>>instance_number;
    perception_learning Classifier(attribute_number, instance_number);
//    int i=0;
    Classifier.print_weight();
    while (instance_number--)
    {
//        cout<<"index:"<<++i<<endl;
        example ex;
        char c;
        string s;
        ex.push_back(1);
        
        for(int i=1;i<=attribute_number;i++)
        {
            cin>>c;
            ex.push_back(c-'0');
        }
//        Classifier.add_to_TrainingSet(ex);
        Classifier.print_example(ex);
//        Classifier.compute_ClassLabel(ex);
//        Classifier.compute_H_ClassLabel(ex);
//        Classifier.print_weight();
        Classifier.Classifying(ex);
    }
//    Classifier.print_TrainingSet();
    Classifier.print_Modifying_Number();
    return 0;
}
//N=0
/*
 11001
 00000
 11111
 11010
 10010
 01001
 10101
 01110
 11011
 01110
 10011
 11110
 01000
 00000
 01010
 00110
 11000
 00010
 01011
 00011
 */
//N=1
/*
 110011
 000001
 111111
 110101
 100100
 010010
 101010
 011100
 110111
 011101
 100111
 111100
 010001
 000001
 010100
 001100
 110000
 000101
 010110
 000110
 */
//N=5
/*
 1100110101
 0000010100
 1111111100
 1101011001
 1001000000
 0100100000
 1010111111
 0111011100
 1101111011
 0111000111
 1001100011
 1111001010
 0100000010
 0000011000
 0101000000
 0011000000
 1100000000
 0001000001
 0101101010
 0001100000
 */
//N=10
//1111111111
//0000000000
/*
 110011111111111
 000000000000000
 111111111111111
 110101111111111
 100100000000000
 010010000000000
 101011111111111
 011101111111111
 110111111111111
 011101111111111
 100110000000000
 111101111111111
 010000000000000
 000000000000000
 010100000000000
 001100000000000
 110000000000000
 000100000000000
 010111111111111
 000110000000000
 */
//N=15
//000000000000000
//111111111111111
/*
 11001111111111111111
 00000000000000000000
 11111111111111111111
 11010111111111111111
 10010000000000000000
 01001000000000000000
 10101111111111111111
 01110111111111111111
 11011111111111111111
 01110111111111111111
 10011111111111111111
 11110111111111111111
 01000000000000000000
 00000000000000000000
 01010000000000000000
 00110000000000000000
 11000000000000000000
 00010000000000000000
 01011111111111111111
 00011000000000000000
 */
//N=20
//11111111111111111111
//00000000000000000000
/*
 1100111111111111111111111
 0000000000000000000000000
 1111111111111111111111111
 1101011111111111111111111
 1001000000000000000000000
 0100100000000000000000000
 1010111111111111111111111
 0111000000000000000000000
 1101111111111111111111111
 0111011111111111111111111
 1001111111111111111111111
 1111011111111111111111111
 0100000000000000000000000
 0000000000000000000000000
 0101000000000000000000000
 0011000000000000000000000
 1100000000000000000000000
 0001000000000000000000000
 0101111111111111111111111
 0001100000000000000000000
 */
