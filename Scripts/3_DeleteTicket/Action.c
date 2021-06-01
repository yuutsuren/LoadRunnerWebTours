Action()
{
	int flight_count_before = 0;
	int flight_count_after = 0;
//	int j;

	
	lr_start_transaction("3_DeleteTicket");
	
	lr_start_transaction("visitSite");

	web_set_sockets_option("SSL_VERSION", "AUTO");
	
	web_reg_find("Text=Welcome to the Web Tours site.", LAST);

	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);

	web_add_cookie("MSO=SID&1622502813; DOMAIN=localhost");

	web_url("home.html", 
		"URL=http://localhost:1080/WebTours/home.html", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/welcome.pl?signOff=true", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);

/*Correlation comment - Do not change!  Original value='131429.956500608zHzAtcipDiHftAfzcpfHADcf' Name ='userSession' Type ='ResponseBased'*/
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
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/welcome.pl?signOff=true", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		LAST);
		
	lr_end_transaction("visitSite", LR_AUTO);

	lr_think_time(17);

	lr_start_transaction("loginPassword");
	
	web_reg_find("Text=Welcome, <b>{login}</b>, to the Web Tours reservation pages.", LAST);

	web_submit_data("login.pl",
		"Action=http://localhost:1080/cgi-bin/login.pl",
		"Method=POST",
		"TargetFrame=body",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home",
		"Snapshot=t13.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=userSession", "Value={userSession}", ENDITEM,
		"Name=username", "Value={login}", ENDITEM,
		"Name=password", "Value={password}", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		"Name=login.x", "Value=45", ENDITEM,
		"Name=login.y", "Value=13", ENDITEM,
		LAST);

	lr_end_transaction("loginPassword",LR_AUTO);

	lr_start_transaction("clickItineraryButton");
	
	web_reg_save_param("flight_ID_origin",
		"LB=name=\"flightID\" value=\"",
		"RB=\"",
		"Ord=ALL",
		LAST);
	
	web_reg_find("Text=Itinerary", LAST);
	
/*Correlation comment - Do not change!  Original value='164611157-788-44' Name ='flightID' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=flightID",
		"TagName=input",
		"Extract=value",
		"Name=flightID",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/itinerary.pl*",
		LAST);

	web_url("Itinerary Button",
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary",
		"TargetFrame=body",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home",
		"Snapshot=t14.inf",
		"Mode=HTML",
		LAST);

	lr_end_transaction("clickItineraryButton",LR_AUTO);
	
		web_reg_save_param("flight_ID",
		"LB=name=\"flightID\" value=\"",
		"RB=\"",
		"Ord=ALL",
		LAST);

	lr_think_time(20);

	lr_start_transaction("deleteTicket");
	
	web_reg_find("Text=Itinerary", LAST);
	
	web_submit_form("itinerary.pl",	
		"Snapshot=t15.inf",
		ITEMDATA,
		"Name=1", "Value=on", ENDITEM,
		"Name=removeFlights.x", "Value=48", ENDITEM,
		"Name=removeFlights.y", "Value=9", ENDITEM,
		LAST);
	
	
	flight_count_before = atoi(lr_eval_string("{flight_ID_origin_count}"));
	flight_count_after = atoi(lr_eval_string("{flight_ID_count}"));
	
	
	if (flight_count_before > flight_count_after) {
	   lr_message("�������� ���������� ����������.");
	   lr_end_transaction("deleteTicket", LR_AUTO);
	} else {
		lr_error_message("�� �������� ���������� ����������.");
		lr_end_transaction("deleteTicket", LR_FAIL);
	}
	
	lr_message("Before deletion - %s", lr_eval_string("{flight_ID_origin_count}"));
	lr_message("After deletion -%s", lr_eval_string("{flight_ID_count}"));

	lr_think_time(16);

	lr_start_transaction("logOut");
	
	web_reg_find("Text=Web Tours", LAST);

	web_url("SignOff Button",
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1",
		"TargetFrame=body",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=itinerary",
		"Snapshot=t16.inf",
		"Mode=HTML",
		LAST);

	lr_end_transaction("logOut",LR_AUTO);
	
	lr_end_transaction("3_DeleteTicket", LR_AUTO);


	return 0;
}
