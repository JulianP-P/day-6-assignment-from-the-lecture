vuser_init()
{
	tName = "01.opening_a_website";
	lr_start_transaction(tName);
/*Correlation comment - Do not change!  Original value='12604.288618874zicAiDDpAQfiDDDDtAQctpQQifHf' Name ='userSession' Type ='ResponseBased'*/
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

	status=web_url("webtours", 
		"URL=http://localhost:1080/webtours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);
	end_transaction(tName, status);
	lr_think_time(4);
	return 0;
}
