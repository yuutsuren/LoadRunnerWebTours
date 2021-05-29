Action()
{
	lr_start_transaction("1_VisitSite");


	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_url("header.html", 
		"URL=http://localhost:1080/WebTours/header.html", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/WebTours/", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);
	

/*Correlation comment - Do not change!  Original value='131413.780315917zHfQfQzpDcftAffHpfHHQf' Name ='userSession' Type ='ResponseBased'*/
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

	web_url("welcome.pl", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=true", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/WebTours/", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(20);

	lr_start_transaction("loginPassword");

/*Correlation comment - Do not change!  Original value='itinerary' Name ='page' Type ='ResponseBased'*/
	web_reg_save_param_regexp(
		"ParamName=page",
		"RegExp=page=(.*?)\"\\ TARGET",
		"Ordinal=2",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/nav.pl*",
		LAST);

/*Correlation comment - Do not change!  Original value='flights' Name ='in' Type ='ResponseBased'*/
	web_reg_save_param_regexp(
		"ParamName=in",
		"RegExp=images/(.*?)\\.gif",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/nav.pl*",
		LAST);

/*Correlation comment - Do not change!  Original value='page' Name ='CorrelationParameter' Type ='RecordReplay'*/
	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter",
		"RegExp=nav\\.pl\\?(\\w+)=",
		SEARCH_FILTERS,
		"Scope=Body",
		"RequestUrl=*/login.pl*",
		LAST);

	web_submit_data("login.pl",
		"Action=http://localhost:1080/cgi-bin/login.pl",
		"Method=POST",
		"TargetFrame=body",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home",
		"Snapshot=t9.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=userSession", "Value={userSession}", ENDITEM,
		"Name=username", "Value={login}", ENDITEM,
		"Name=password", "Value={password}", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		"Name=login.x", "Value=47", ENDITEM,
		"Name=login.y", "Value=9", ENDITEM,
		LAST);

	web_convert_param("CorrelationParameter_URL3",
		"SourceString={CorrelationParameter}",
		"SourceEncoding=HTML",
		"TargetEncoding=URL",
		LAST);

	web_convert_param("CorrelationParameter_URL2",
		"SourceString={CorrelationParameter}",
		"SourceEncoding=HTML",
		"TargetEncoding=URL",
		LAST);

	web_convert_param("CorrelationParameter_URL1",
		"SourceString={CorrelationParameter}",
		"SourceEncoding=HTML",
		"TargetEncoding=URL",
		LAST);

	web_convert_param("CorrelationParameter_PLAIN",
		"SourceString={CorrelationParameter}",
		"SourceEncoding=HTML",
		"TargetEncoding=PLAIN",
		LAST);
		
		web_reg_find("Text=Welcome.", LAST);

	lr_end_transaction("loginPassword",LR_AUTO);

	lr_start_transaction("clickFlightsButton");

/*Correlation comment - Do not change!  Original value='roundtrip' Name ='.cgifields' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=.cgifields",
		"TagName=input",
		"Extract=name",
		"Type=checkbox",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/reservations.pl*",
		LAST);

	web_url("Search Flights Button",
		"URL=http://localhost:1080/cgi-bin/welcome.pl?{CorrelationParameter}=search",
		"TargetFrame=body",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/nav.pl?{CorrelationParameter}=menu&in=home",
		"Snapshot=t10.inf",
		"Mode=HTML",
		LAST);

	lr_end_transaction("clickFlightsButton",LR_AUTO);

	lr_think_time(20);

	lr_start_transaction("flightSettings");

/*Correlation comment - Do not change!  Original value='561;67;05/30/2021' Name ='outboundFlight' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=outboundFlight",
		"TagName=input",
		"Extract=value",
		"Name=outboundFlight",
		"Type=radio",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		LAST);

	web_submit_data("reservations.pl",
		"Action=http://localhost:1080/cgi-bin/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/reservations.pl?{CorrelationParameter}=welcome",
		"Snapshot=t11.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=depart", "Value={departCity}", ENDITEM,
		"Name=departDate", "Value={departDate}", ENDITEM,
		"Name=arrive", "Value={arrivalCity}", ENDITEM,
		"Name=returnDate", "Value={returnDate}", ENDITEM,
		"Name=numPassengers", "Value={numPassengers}", ENDITEM,
		"Name=seatPref", "Value={seatPref}", ENDITEM,
		"Name=seatType", "Value={seatType}", ENDITEM,
		"Name=.cgifields", "Value={.cgifields}", ENDITEM,
		"Name=.cgifields", "Value={seatType}", ENDITEM,
		"Name=.cgifields", "Value={seatPref}", ENDITEM,
		"Name=findFlights.x", "Value=47", ENDITEM,
		"Name=findFlights.y", "Value=12", ENDITEM,
		LAST);

	lr_end_transaction("flightSettings",LR_AUTO);

	lr_think_time(16);

	lr_start_transaction("flightSelection");

	web_submit_data("reservations.pl_2",
		"Action=http://localhost:1080/cgi-bin/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/reservations.pl",
		"Snapshot=t12.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=outboundFlight", "Value={outboundFlight}", ENDITEM,
		"Name=numPassengers", "Value=1", ENDITEM,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=seatType", "Value={seatType}", ENDITEM,
		"Name=seatPref", "Value={seatPref}", ENDITEM,
		"Name=reserveFlights.x", "Value=48", ENDITEM,
		"Name=reserveFlights.y", "Value=9", ENDITEM,
		LAST);

	lr_end_transaction("flightSelection",LR_AUTO);

	lr_think_time(12);

	lr_start_transaction("paymentData");

	web_submit_data("reservations.pl_3",
		"Action=http://localhost:1080/cgi-bin/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/reservations.pl",
		"Snapshot=t13.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=firstName", "Value={firstName}", ENDITEM,
		"Name=lastName", "Value={lastName}", ENDITEM,
		"Name=address1", "Value={adress}", ENDITEM,
		"Name=address2", "Value={cityStateZip}", ENDITEM,
		"Name=pass1", "Value={firstName} {lastName}", ENDITEM,
		"Name=creditCard", "Value={creditCard}", ENDITEM,
		"Name=expDate", "Value={expDate}", ENDITEM,
		"Name=saveCC", "Value=on", ENDITEM,
		"Name=oldCCOption", "Value=on", ENDITEM,
		"Name=numPassengers", "Value={numPassengers}", ENDITEM,
		"Name=seatType", "Value={seatType}", ENDITEM,
		"Name=seatPref", "Value={seatPref}", ENDITEM,
		"Name=outboundFlight", "Value={outboundFlight}", ENDITEM,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=returnFlight", "Value=", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		"Name=.cgifields", "Value=saveCC", ENDITEM,
		"Name=buyFlights.x", "Value=41", ENDITEM,
		"Name=buyFlights.y", "Value=11", ENDITEM,
		LAST);

	lr_end_transaction("paymentData",LR_AUTO);

	lr_think_time(14);

	lr_start_transaction("clickItineraryButton");

/*Correlation comment - Do not change!  Original value='20576154-235-55' Name ='flightID' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=flightID",
		"TagName=input",
		"Extract=value",
		"Name=flightID",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/{page}.pl*",
		LAST);

/*Correlation comment - Do not change!  Original value='205743733-1599-55' Name ='flightID_1' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=flightID_1",
		"TagName=input",
		"Extract=value",
		"Name=flightID",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/{page}.pl*",
		LAST);

/*Correlation comment - Do not change!  Original value='2057574117-7781-55' Name ='flightID_2' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=flightID_2",
		"TagName=input",
		"Extract=value",
		"Name=flightID",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/{page}.pl*",
		LAST);
		
		lr_start_transaction("2_DeleteTickets");


	web_url("Itinerary Button",
		"URL=http://localhost:1080/cgi-bin/welcome.pl?{CorrelationParameter}={page}",
		"TargetFrame=body",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/nav.pl?{CorrelationParameter}=menu&in={in}",
		"Snapshot=t14.inf",
		"Mode=HTML",
		LAST);

	lr_end_transaction("clickItineraryButton",LR_AUTO);

	lr_think_time(30);

	lr_start_transaction("selectAndDeleteAlltickets");

	web_submit_data("itinerary.pl",
		"Action=http://localhost:1080/cgi-bin/{page}.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/{page}.pl",
		"Snapshot=t15.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=1", "Value=on", ENDITEM,
		"Name=flightID", "Value={flightID_2}", ENDITEM,
		"Name=2", "Value=on", ENDITEM,
		"Name=flightID", "Value={flightID_1}", ENDITEM,
		"Name=3", "Value=on", ENDITEM,
		"Name=flightID", "Value={flightID}", ENDITEM,
		"Name=.cgifields", "Value=1", ENDITEM,
		"Name=.cgifields", "Value=3", ENDITEM,
		"Name=.cgifields", "Value=2", ENDITEM,
		"Name=removeFlights.x", "Value=43", ENDITEM,
		"Name=removeFlights.y", "Value=11", ENDITEM,
		LAST);

	lr_end_transaction("selectAndDeleteAlltickets",LR_AUTO);
	
	lr_end_transaction("2_DeleteTickets", LR_AUTO);


	lr_think_time(9);

	lr_start_transaction("logOut");

	web_url("SignOff Button",
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1",
		"TargetFrame=body",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/nav.pl?{CorrelationParameter}=menu&in={page}",
		"Snapshot=t16.inf",
		"Mode=HTML",
		LAST);

	lr_end_transaction("logOut",LR_AUTO);
	
	lr_end_transaction("1_VisitSite", LR_AUTO);


	return 0;
}
