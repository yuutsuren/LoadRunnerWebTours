Action()
{
	lr_start_transaction("2_SearchAndBuyTicket");
	
	lr_start_transaction("visitSite");
	
	web_reg_find("Text=Welcome to the Web Tours site.", LAST);

	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t22.inf", 
		"Mode=HTML", 
		LAST);

	web_add_cookie("MSO=SID&1622551560; DOMAIN=localhost");

	web_url("home.html", 
		"URL=http://localhost:1080/WebTours/home.html", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/welcome.pl?signOff=true", 
		"Snapshot=t23.inf", 
		"Mode=HTML", 
		LAST);
	
	web_reg_save_param_attrib(
		"ParamName=userSession",
		"TagName=input",
		"Extract=value",
		"Name=userSession",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/nav.pl*",
		LAST);

	web_url("nav.pl", 
		"URL=http://localhost:1080/cgi-bin/nav.pl?in=home", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/welcome.pl?signOff=true", 
		"Snapshot=t24.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction("visitSite", LR_AUTO);

	lr_start_transaction("loginPassword");
	
	web_reg_find("Text=Welcome, <b>{login}</b>, to the Web Tours reservation pages.", LAST);

	web_submit_form("login.pl", 
		"Snapshot=t25.inf", 
		ITEMDATA, 
		"Name=userSession", "Value={userSession}", ENDITEM,
		"Name=username", "Value={login}", ENDITEM, 
		"Name=password", "Value={password}", ENDITEM, 
		"Name=login.x", "Value=53", ENDITEM, 
		"Name=login.y", "Value=10", ENDITEM, 
		LAST);

	lr_end_transaction("loginPassword",LR_AUTO);

	lr_start_transaction("clickFlightsButton");
	
	web_reg_find("Text=Find Flight", LAST);

	web_image("Search Flights Button", 
		"Alt=Search Flights Button", 
		"Snapshot=t26.inf", 
		LAST);

	lr_end_transaction("clickFlightsButton",LR_AUTO);

	lr_think_time(23);

	lr_start_transaction("flightSettings");
	
	web_reg_find("Text=Find Flight", LAST);

/*Correlation comment - Do not change!  Original value='173;417;06/02/2021' Name ='outboundFlight' Type ='ResponseBased'*/
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
		"Snapshot=t27.inf", 
		ITEMDATA, 
		"Name=depart", "Value={departCity}", ENDITEM, 
		"Name=departDate", "Value={departDate}", ENDITEM, 
		"Name=arrive", "Value={arrivalCity}", ENDITEM, 
		"Name=returnDate", "Value={returnDate}", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=roundtrip", "Value=<OFF>", ENDITEM, 
		"Name=seatPref", "Value={seatPref}", ENDITEM, 
		"Name=seatType", "Value={seatType}", ENDITEM, 
		"Name=findFlights.x", "Value=48", ENDITEM, 
		"Name=findFlights.y", "Value=11", ENDITEM, 
		LAST);

	lr_end_transaction("flightSettings",LR_AUTO);

	lr_think_time(24);

	lr_start_transaction("flightSelection");
	
	web_reg_find("Text=Payment Details", LAST);

	web_submit_form("reservations.pl_2",
		"Snapshot=t28.inf",
		ITEMDATA,
		"Name=outboundFlight", "Value={outboundFlight}", ENDITEM,
		"Name=reserveFlights.x", "Value=45", ENDITEM,
		"Name=reserveFlights.y", "Value=8", ENDITEM,
		LAST);

	lr_end_transaction("flightSelection",LR_AUTO);
	
	lr_think_time(16);

	lr_start_transaction("paymentData");
	
	web_reg_find("Text=Thank you for booking through Web Tours.", LAST);

	  web_submit_form("reservations.pl_3", 
		"Snapshot=t29.inf", 
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
		"Name=buyFlights.y", "Value=9", ENDITEM, 
		LAST);
	

	lr_end_transaction("paymentData",LR_AUTO);

	lr_think_time(15);

	lr_start_transaction("clickItineraryButton");
	
	web_reg_find("Text=Itinerary", LAST);
	
	web_image("Itinerary Button", 
		"Alt=Itinerary Button", 
		"Snapshot=t30.inf", 
		LAST);

	lr_end_transaction("clickItineraryButton",LR_AUTO);
	
	lr_think_time(11);
	
//	lr_start_transaction("logOut");
//	
//	web_reg_find("Text=Web Tours", LAST);
//
//	web_image("SignOff Button", 
//		"Alt=SignOff Button", 
//		"Snapshot=t31.inf", 
//		LAST);
//
//	lr_end_transaction("logOut",LR_AUTO);
	
	lr_end_transaction("2_SearchAndBuyTicket", LR_AUTO);


	return 0;
}
