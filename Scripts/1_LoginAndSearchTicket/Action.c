Action()
{
	lr_start_transaction("1_LoginAndSearchTicket");
	
	lr_start_transaction("visitSite");
	
	web_reg_find("Text=Welcome to the Web Tours site.", LAST);

	web_reg_save_param_regexp(
	    "ParamName=userSession", 
	    "RegExp=name=\"userSession\" value=\"([^\"]+)\"/>",
	    "Ordinal=1",
		LAST);
 	
	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction("visitSite", LR_AUTO);

	lr_think_time(13);

	lr_start_transaction("loginPassword");
	
	web_reg_find("Text=Welcome", LAST);
	
	web_submit_form("login.pl", 
		"Snapshot=t2.inf", 
		ITEMDATA,
		"Name=username", "Value={login}", ENDITEM, 
		"Name=password", "Value={password}", ENDITEM, 
		"Name=login.x", "Value=44", ENDITEM, 
		"Name=login.y", "Value=11", ENDITEM, 
		LAST);

	lr_end_transaction("loginPassword",LR_AUTO);

	lr_start_transaction("clickFlightsButton");
	
	web_reg_find("Text=Web Tours", LAST);

	web_image("Search Flights Button", 
		"Alt=Search Flights Button", 
		"Snapshot=t3.inf", 
		LAST);

	lr_end_transaction("clickFlightsButton",LR_AUTO);

	lr_think_time(17);

	lr_start_transaction("flightSettings");
	
	web_reg_find("Text=Find Flight", LAST);

	web_submit_form("reservations.pl", 
		"Snapshot=t4.inf", 
		ITEMDATA, 
		"Name=depart", "Value={departCity}", ENDITEM, 
		"Name=departDate", "Value={departDate}", ENDITEM, 
		"Name=arrive", "Value={arrivalCity}", ENDITEM, 
		"Name=returnDate", "Value={returnDate}", ENDITEM, 
		"Name=numPassengers", "Value=", ENDITEM, 
		"Name=roundtrip", "Value=<OFF>", ENDITEM, 
		"Name=seatPref", "Value={seatPref}", ENDITEM, 
		"Name=seatType", "Value={seatType}", ENDITEM, 
		"Name=findFlights.x", "Value=46", ENDITEM, 
		"Name=findFlights.y", "Value=12", ENDITEM, 
		LAST);

	lr_end_transaction("flightSettings",LR_AUTO);

	lr_think_time(13);

	lr_start_transaction("logOut");
	
	web_reg_find("Text=Web Tours", LAST);

	web_image("SignOff Button", 
		"Alt=SignOff Button", 
		"Snapshot=t5.inf", 
		LAST);

	lr_end_transaction("logOut",LR_AUTO);
	
	lr_end_transaction("1_LoginAndSearchTicket", LR_AUTO);


	return 0;
}
