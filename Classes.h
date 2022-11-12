//
// Created by lyaho on 12.11.2022.
//
#include<iostream>
#include<string>

#ifndef CP3_TASK1_CLASSES_H
#define CP3_TASK1_CLASSES_H


class Person {
public:
    Person(std::string f_name, std::string l_name): first_name(f_name), last_name(l_name){};
    void Show(char end_of_string = '\n'){
        std::cout << first_name << " " << last_name << end_of_string;
    }
protected:
    std::string first_name;
    std::string last_name;

};

class Gunslinger: virtual public Person{
public:
    Gunslinger(std::string f_name, std::string l_name, int comp = 0):Person(f_name, l_name), competitions(comp){}
    double Draw(){
        if (competitions == 0){
            return 100.0;
        }
        return 1 - 1/(double)competitions;
    }
    void Show(){
        Person::Show(',');
        std::cout << " competitions: " << competitions << std::endl;
    }

protected:
    int competitions;
};

class PokerPlayer: virtual public Person{
public:
    PokerPlayer(std::string f_name, std::string l_name): Person(f_name, l_name){}
    int Draw(){
        return 13;
    }
    void Show(){
        Person::Show();
    }
};

class BadDude: public Gunslinger, public PokerPlayer{
public:
    BadDude(std::string f_name, std::string l_name): Gunslinger(f_name, l_name, 0),
    Person(f_name, l_name), PokerPlayer(f_name, l_name){}
    double Gdraw(){
        return 1.05;
    }
    int Cdraw(){
        PokerPlayer::Draw();
    }
    void Show(){
        Person::Show();
    }
};


#endif //CP3_TASK1_CLASSES_H
