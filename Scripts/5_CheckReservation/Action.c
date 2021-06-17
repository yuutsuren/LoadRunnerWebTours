Action()
{
	lr_start_transaction("5_CheckReservation");

	lr_start_transaction("visitSite");
	
	web_reg_find("Text=Welcome to the Web Tours site.", LAST);

/*Correlation comment - Do not change!  Original value='131458.579505873zHzVQAApziDDDDDDtAfHVptAtV' Name ='userSession' Type ='ResponseBased'*/
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

	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);
		
	lr_end_transaction("visitSite", LR_AUTO);

	lr_think_time(18);

	lr_start_transaction("loginPassword");
	
	web_reg_find("Text=Welcome, <b>{login}</b>, to the Web Tours reservation pages.", LAST);

	web_submit_data("login.pl",
		"Action=http://localhost:1080/cgi-bin/login.pl",
		"Method=POST",
		"TargetFrame=body",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home",
		"Snapshot=t6.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=userSession", "Value={userSession}", ENDITEM,
		"Name=username", "Value={login}", ENDITEM,
		"Name=password", "Value={password}", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		"Name=login.x", "Value=63", ENDITEM,
		"Name=login.y", "Value=11", ENDITEM,
		LAST);

	lr_end_transaction("loginPassword",LR_AUTO);

	lr_start_transaction("clickItineraryButton");
	
	web_reg_find("Text=Itinerary", LAST);

	web_url("Itinerary Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("clickItineraryButton",LR_AUTO);

	lr_think_time(13);

	lr_start_transaction("logOut");
	
	web_reg_find("Text=Welcome to the Web Tours site.", LAST);

	web_url("SignOff Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction("logOut", LR_AUTO);
	
	lr_end_transaction("5_CheckReservation", LR_AUTO);



	return 0;
}
