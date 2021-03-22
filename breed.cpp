#include <iostream>
#include <list>
#include <iterator>
using namespace std;

Engimon Trainer::breeding(Engimon a, Engimon b){
    if (a.level > 30 && b.level > 30){
        //proses
        /*Skill //asumsi kumpulan skill pakai stl list
        list<Skill> concatSkill;
        list<Skill> childSkill;
        concatSkill.insert(concatSkill.end(), a.learnedSkill.begin(), a.learnedSkill.end());
        concatSkill.insert(concatSkill.end(), b.learnedSkill.begin(), b.learnedSkill.end());
        if (concatSkill.size() > 4){
            concatSkill.sort([] (Skill * first, Skill * second) {return first.masteryLevel > second.masteryLevel;});
            childSkill.insert(childSkill.end(), concatSkill.begin(), 4);
        } else{
            //langsung ambil
            childSkill.insert(childtSkill.end(), concatSkill.begin(), concatSkill.end());
        }//masih belum ada penanganan kasus mastery level sama dan skill dimiliki kedua parent
        */
        /* Elements
        list<Elements> childElements;
        if (a.elements==(b.elements)){ //operator
            childElements = a.elements; //copy
        } else{
            if (//type_adventage(a,b) > type_adventage(b,a)){
               childElements = a.elements;
            } else if (//type_adventage(a,b) < type_adventage(b,a)){
               childElements = b.elements;
            } else {
               childElements = concat(a.elements, b,elements);
            }
        }
        */
        string nama;
        cin << nama;
        Engimon child = new Engimon(nama, a, b, spesies, childSkill, childElements)//ini belum dibuat
        a.level -= 30;
        b.level -= 30;
        return child;
    } else{
        //pesan kesalahan
        return;
    }
}