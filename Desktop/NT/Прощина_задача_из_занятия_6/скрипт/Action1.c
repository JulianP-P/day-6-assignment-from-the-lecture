Action1()
{
		/* login */
	tName = "02.Login";
	lr_start_transaction(tName);
	status=web_submit_data("login.pl",
		"Action=http://localhost:1080/cgi-bin/login.pl",
		"Method=POST",
		"TargetFrame=body",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home",
		"Snapshot=t2.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=userSession", "Value={userSession}", ENDITEM,
		"Name=username", "Value=jojo", ENDITEM,
		"Name=password", "Value=bean", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		"Name=login.x", "Value=34", ENDITEM,
		"Name=login.y", "Value=1", ENDITEM,
		LAST);
		
	end_transaction(tName, status);
	lr_think_time(4);
	return 0;
}