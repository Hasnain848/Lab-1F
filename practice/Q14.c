#include<stdio.h>
#include<string.h>
struct Customerinfo{
	char Name[50];
	char Address[100];
};
struct Car{
	float price;
	int Model;
	char Brand[50];
	int Manufacturing_date[3];
	char Countryoforigin[30];
	struct Customerinfo data;
}; 
float serviceTax();
float retailProfit();
float importDutytax();
float salesTax();
float calculatePrice();
int main(){
	
}
float serviceTax(float price){
	float service;
	service=(0.06)*price;
	return service;
}
float retailProfit(float price){
	float retail;
	retail=(0.75)*price;
	return retail;
}
float importDutytax(float price){
		float duty;
        duty=(0.15)*price;
	return duty;
}
float salesTax(float price,int flag){
	float sales;
	switch(flag){
		case 1: sales=(0.1)*price;return sales;break;
		case 2: sales=(0.065)*price;return sales;break;
	}
}
float calculatePrice(float price,int flag){
	float dutytax=importDutytax(price);
	float salestax=salesTax(float price,int flag);
	float retailprofit=retailProfit(price+dutytax+salestax)
	float gst=serviceTax(price+dutytax+salestax+retailprofit);
	return price+dutytax+salestax+retailprofit+gst;
	
}