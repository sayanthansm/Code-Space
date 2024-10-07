#include<iostream>
#include<string.h>
using namespace std;
class weather
{
private:
    string city;
    float tempincelsius;
    int humidity;
    float preciptation;
    
public:
    weather(string _city,float _temperature,int _humidity,float _preciptation){
        city=_city;
        tempincelsius=_temperature;
        humidity=_humidity;
        preciptation=_preciptation;

    }
    float tofarenheit(){
        return (tempincelsius * 9/5) + 32;
    }
    void displayforecast(){
        cout<<"Weather Forecast in "<<city<<endl;
         cout << "Temperature: " << tempincelsius << " Celsius (" << tofarenheit() << " Fahrenheit)" << endl;
        cout<<"Humidity rate is "<<humidity<<"%"<<endl;
        cout<<"preciptation is "<<preciptation<<endl;
    }
    };
int main(){
    string city;
    float _temp;
    float _humidity;
    float _preciptation;
    cout<<"Enter city name: "<<"\n";
    cin>>city;
    cout<<"Enter temperature(in degree celsius): "<<"\n";
    cin>>_temp;
    cout<<"Enter humidity: "<<"\n";
    cin>>_humidity;
    
    cout<<"Enter preciptation: "<<"\n";
    cin>>_preciptation;
    weather Weather(city,_temp,_humidity,_preciptation);
    Weather.displayforecast();
    return 0;


}