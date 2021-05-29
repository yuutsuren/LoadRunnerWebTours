Action()
{
	lr_start_transaction("1_VisitSite");


	web_set_sockets_option("SSL_VERSION", "AUTO");
	

	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);
	

	lr_think_time(15);

	lr_start_transaction("loginPassword");

	
	web_reg_find("Text=User password was correct", LAST );
	
	
	web_submit_form("login.pl", 
		"Snapshot=t2.inf", 
		ITEMDATA, 
		"Name=username", "Value={login}", ENDITEM, 
		"Name=password", "Value={password}", ENDITEM, 
		"Name=login.x", "Value=36", ENDITEM, 
		"Name=login.y", "Value=12", ENDITEM, 
		LAST);

	lr_end_transaction("loginPassword",LR_AUTO);
	
		
	lr_start_transaction("clickFlightsButton");

	web_image("Search Flights Button", 
		"Alt=Search Flights Button", 
		"Snapshot=t3.inf", 
		LAST);

	lr_end_transaction("clickFlightsButton",LR_AUTO);

	lr_think_time(26);

	lr_start_transaction("flightSettings");

/*Correlation comment - Do not change!  Original value='581;1345;05/30/2021' Name ='outboundFlight' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=outboundFlight",
		"TagName=input",
		"Extract=value",
		"Name=outboundFlight",
		"Type=radio",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		LAST);

	web_submit_form("reservations.pl", 
		"Snapshot=t4.inf", 
		ITEMDATA, 
		"Name=depart", "Value={departCity}", ENDITEM, 
		"Name=departDate", "Value={departDate}", ENDITEM, 
		"Name=arrive", "Value={arrivalCity}", ENDITEM, 
		"Name=returnDate", "Value={returnDate}", ENDITEM, 
		"Name=numPassengers", "Value={numPassengers}", ENDITEM, 
		"Name=roundtrip", "Value=<OFF>", ENDITEM, 
		"Name=seatPref", "Value={seatPref}", ENDITEM, 
		"Name=seatType", "Value={seatType}", ENDITEM, 
		"Name=findFlights.x", "Value=49", ENDITEM, 
		"Name=findFlights.y", "Value=12", ENDITEM, 
		LAST);

	lr_end_transaction("flightSettings",LR_AUTO);

	lr_think_time(26);

	lr_start_transaction("flightSelection");

	web_submit_form("reservations.pl_2",
		"Snapshot=t5.inf",
		ITEMDATA,
		"Name=outboundFlight", "Value={outboundFlight}", ENDITEM,
		"Name=reserveFlights.x", "Value=49", ENDITEM,
		"Name=reserveFlights.y", "Value=10", ENDITEM,
		LAST);

	lr_end_transaction("flightSelection",LR_AUTO);

	lr_think_time(12);

	lr_start_transaction("paymentData");

	web_submit_form("reservations.pl_3", 
		"Snapshot=t6.inf", 
		ITEMDATA, 
		"Name=firstName", "Value={firstName}", ENDITEM, 
		"Name=lastName", "Value={lastName}", ENDITEM, 
		"Name=address1", "Value={adress}", ENDITEM, 
		"Name=address2", "Value={cityStateZip}", ENDITEM, 
		"Name=pass1", "Value={firstName} {lastName}", ENDITEM, 
		"Name=creditCard", "Value={creditCard}", ENDITEM, 
		"Name=expDate", "Value={expDate}", ENDITEM, 
		"Name=saveCC", "Value=on", ENDITEM, 
		"Name=buyFlights.x", "Value=48", ENDITEM, 
		"Name=buyFlights.y", "Value=10", ENDITEM, 
		LAST);

	lr_end_transaction("paymentData",LR_AUTO);

	lr_think_time(15);
	
	lr_start_transaction("2_DeleteTicket");

	lr_start_transaction("clickItineraryButton");

	web_image("Itinerary Button", 
		"Alt=Itinerary Button", 
		"Snapshot=t7.inf", 
		LAST);

	lr_end_transaction("clickItineraryButton",LR_AUTO);
	

	lr_think_time(19);
	
	lr_start_transaction("deleteTicket");
	
	
	web_submit_form("itinerary.pl", 
		"Snapshot=t8.inf", 
		ITEMDATA, 
		"Name=1", "Value=<OFF>", ENDITEM, 
		"Name=2", "Value=on", ENDITEM, 
		"Name=3", "Value=<OFF>", ENDITEM, 
		"Name=removeFlights.x", "Value=40", ENDITEM, 
		"Name=removeFlights.y", "Value=11", ENDITEM, 
		LAST);
	

	lr_end_transaction("deleteTicket",LR_AUTO);
	
	lr_end_transaction("2_DeleteTicket", LR_AUTO);


	lr_think_time(8);

	lr_start_transaction("logOut");

	web_image("SignOff Button", 
		"Alt=SignOff Button", 
		"Snapshot=t9.inf", 
		LAST);

	lr_end_transaction("logOut",LR_AUTO);

	lr_end_transaction("1_VisitSite", LR_AUTO);

	return 0;
}
