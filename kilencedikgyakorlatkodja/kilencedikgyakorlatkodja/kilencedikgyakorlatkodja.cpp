#include <algorithm>
#include <iostream>
#include <list>
#include <set>
#include <string>
#include <vector>
#include <numeric>
#include <random>
using namespace std;
template<typename T>
void display(const T& collection)
{
    std::string separator = "";
    for (const auto& current : collection)
    {
        std::cout << separator << current;
        separator = ", ";
    }
    std::cout << std::endl;
}
struct Student
{
    string mName; 
    uint8_t mAge;
    bool operator==(const Student& other) const 
    {
        return mName == other.mName && mAge == other.mAge;
    }
    bool operator<(const Student& other) const
    {
        if (mAge==other.mAge)
        {
            return mName < other.mName;
        }
        else
        {
            return mAge < other.mAge;
        }
    }
};
int main()
{
    ////std::cout << "Hello World!\n";
    //std::vector<int> v{ 1,8,4,2,9,7,6,4,1,2 };
    vector<Student> students{ {"hallgato Helga",18}, {"Hallgato Hugo",21} };//Csak a pod(csak elemi tagokat tartalmazó) jellegû structoknál alapból létrejön a tagokat tartalmazó constructor
    //std::find(v.cbegin(), v.cend(), 5);//const iterátor ha cbegin()/cend() ha begin()/end() akkor sima iterátor
    //display(v);
    ////std::find(v.rbegin(), v.rend(), 5);//Hátúlról reverse iterátor
    //std::sort(v.begin(), v.end());

    //std::list<int> l{ 1, 4, 6, 9, 2 };
    //std::find(v.cbegin(), v.cend(), 3);
    //display(l);

    //std::set<int> s{ 1, 4, 6, 8 };
    //std::find(v.cbegin(), v.cend(), 4);
    //display(s);

    //std::string myString = "example";
    //std::find(myString.cbegin(), myString.cend(), 'a');
    //display(myString);

    //Összegzés

    ////const auto act=accumulate(v.cbegin(), v.cend(), 0);//Összeg
    //const auto act = accumulate(v.cbegin(), v.cend(), 1, [](auto& temp, const auto& current){return temp *= current; });//lamda elsõje mindig a ami van a második ami jön ha tesztelnéd (cout <<"Temp" << temp << endl;cout << current << endl;cout << act << endl;)

    ////Eldöntés
    //const auto anyOf=any_of(v.cbegin(), v.cend(), [](const auto& current) {return current%2==0; });
    //cout << boolalpha << anyOf << endl;
    //const auto allOff = all_of(v.cbegin(), v.cend(), [](const auto& current) {return current % 2 == 0; });
    //cout << boolalpha << allOff << endl;
    //const auto noneOff = none_of(v.cbegin(), v.cend(), [](const auto& current) {return current >= 10; });
    //cout << boolalpha << noneOff << endl;

    ////Lineáris keresés
    ////Spéci eset konkrét értékre
    //const auto it=std::find(v.cbegin(), v.cend(), 6);
    //if (it!=v.cend())
    //{
    //    const auto index = distance(v.cbegin(), it);
    //    cout <<index<<":\t" << *it << endl;
    //}
    //else
    //{
    //    cout << "Missing" << endl;
    //}
    //vector<Student> students{ {"hallgato Helga",18}, {"Hallgato Hugo",21} };//Csak a pod(csak elemi tagokat tartalmazó) jellegû structoknál alapból létrejön a tagokat tartalmazó constructor
    //std::find(students.cbegin(), students.cend(), Student{ "hallgato Hugo",20 });
    ////Nem spéci eset predikátumra
    //const auto it = std::find_if(v.cbegin(), v.cend(), [](const auto& current) {return current % 3 == 0; });
    //
    ////Megszámlálás
    //const auto counter = count(v.cbegin(), v.cend(), 4);
    //cout << counter << endl;
    //const auto counterif = count_if(v.cbegin(), v.cend(), [](const auto& current) {return current == 4; });


    //Maximumkiválasztás
    //const auto it=max_element(v.cbegin(), v.cend());
    //const auto it=max_element(v.cbegin(), v.cend(), std::less<int>());//macium
    //const auto it= max_element(v.cbegin(), v.cend(), std::greater<int>());//minimum
    //cout << distance(v.cbegin(),it) << endl;
    //max_element(students.cbegin(), students.cend());
    //const auto it=min_element(v.cbegin(), v.cend());
    //const auto [minIt, maxIt] = minmax_element(v.cbegin(), v.cend());

    //Másolás

    //vector<int> w;

    //transform(v.cbegin(), v.cend(), back_inserter(w), [](const auto& current) {return current * current; });
    //display(w);
    //copy(v.cbegin(), v.cend(), w.begin(), std::back_inserter(w));
    //display(w);
    //copy_if(v.cbegin(), v.cend(), w.begin(), back_inserter(w), [](const auto& current) {return current % 2 == 0; });
    //display(w);


    //Szétválogatás

    //const auto it=partition(v.begin(), v.end(), [](const auto& current) {return current % 2 == 0; });
    //const auto it = stable_partition(v.begin(), v.end(), [](const auto& current) {return current % 2 == 0; });
    //cout <<"Index: \t" << distance(v.begin(), it) << endl;
    //display(v);
    //const auto isPartitioned = is_partitioned(v.cbegin(), v.cend(), [](const auto& current) {return current % 2 == 0; });
    //cout << boolalpha<<isPartitioned << endl;


    //Rendezettség

    //sort(v.begin(), v.end());//Quick-Sort ha nagy a lépésszám akkor Heap-Sort
    //display(v);
    //const auto isSorted=is_sorted(v.cbegin(), v.cend());
    //cout << boolalpha << isSorted << endl;

    //Bináris Keresés(Logaritmikus keresés)

    //const bool isContained=binary_search(v.cbegin(), v.cend(), 6);//Feltételezi, hogy rendezett de nem vizsgálja
    //cout << boolalpha << isContained << endl;

    //const auto itLower=lower_bound(v.cbegin(), v.cend(), 4);
    //const auto itUpper = upper_bound(v.cbegin(), v.cend(), 4);
    ////if (it!=v.cend()&&*it==3)
    ////{
    ////    //Valójában jó az eredménye a loweboundnak
    ////}
    //cout << distance(v.cbegin(), itLower) << endl;
    //cout << distance(v.cbegin(), itUpper) << endl;//Az utolsó elõforduló elem utáni elem 
    //const auto [lowerIt, upperIt] = equal_range(v.cbegin(), v.cend(), 4);

    //Halmaz

    //std::vector<int> v1{ 1,3,5,5,7,9,11 };
    //display(v1);
    //std::vector<int> v2{ 1,2,3,4,4,6,9,9,10,12 };
    //display(v2);

    //vector<int> w;

    //set_union(v1.cbegin(), v1.cend(), v2.cbegin(), v2.cend(), back_inserter(w));//Itt minden másik halmazmûvelet
    //display(w);

    //const bool doesInclude = includes(v1.cbegin(), v1.cend(), v2.cbegin(), v2.cend());

    //merge(v1.cbegin(), v1.cend(), v2.cbegin(), v2.cend(), back_inserter(w));
    //display(w);


    //ETC

    
    vector<int> v3(11);
    iota(v3.begin(), v3.end(), 0);
    display(v3);
    
    random_device device;
    shuffle(v3.begin(), v3.end(), device);
    display(v3);

}
