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

	lr_think_time(16);

	lr_start_transaction("loginPassword");
	
	web_submit_data("login.pl", 
		"Action=http://192.168.26.1:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=body", 
		"RecContentType=text/html", 
		"Referer=http://192.168.26.1:1080/cgi-bin/nav.pl?in=home", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value={userSession}", ENDITEM, 
		"Name=username", "Value={login}", ENDITEM, 
		"Name=password", "Value={password}", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=login.x", "Value=50", ENDITEM, 
		"Name=login.y", "Value=11", ENDITEM, 
		LAST);
	
	lr_end_transaction("loginPassword",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("clickFlightsButton");

	web_image("Search Flights Button", 
		"Alt=Search Flights Button", 
		"Snapshot=t3.inf", 
		LAST);

	lr_end_transaction("clickFlightsButton",LR_AUTO);

	lr_think_time(28);

	lr_start_transaction("flightSettings");

/*Correlation comment - Do not change!  Original value='181;1575;05/30/2021' Name ='outboundFlight' Type ='ResponseBased'*/
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
		"Name=findFlights.x", "Value=45", ENDITEM, 
		"Name=findFlights.y", "Value=10", ENDITEM, 
		LAST);

	lr_end_transaction("flightSettings",LR_AUTO);

	lr_think_time(26);

	lr_start_transaction("flightSelection");

	web_submit_form("reservations.pl_2",
		"Snapshot=t5.inf",
		ITEMDATA,
		"Name=outboundFlight", "Value={outboundFlight}", ENDITEM,
		"Name=reserveFlights.x", "Value=42", ENDITEM,
		"Name=reserveFlights.y", "Value=12", ENDITEM,
		LAST);

	lr_end_transaction("flightSelection",LR_AUTO);

	lr_think_time(12);
	
	lr_start_transaction("2_BuyTicket");

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
		"Name=buyFlights.x", "Value=46", ENDITEM, 
		"Name=buyFlights.y", "Value=7", ENDITEM, 
		LAST);

	lr_end_transaction("paymentData",LR_AUTO);
	
	lr_end_transaction("2_BuyTicket", LR_AUTO);


	lr_think_time(21);

	lr_start_transaction("logOut");

	web_image("SignOff Button", 
		"Alt=SignOff Button", 
		"Snapshot=t7.inf", 
		LAST);

	lr_end_transaction("logOut",LR_AUTO);
	
	lr_end_transaction("VisitSite", LR_AUTO);


	return 0;
}
