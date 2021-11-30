Action2()
{
	tName = "03.flights";
	lr_start_transaction(tName);
	
		/* flights */
		status=web_url("Search Flights Button", 
			"URL=http://localhost:1080/cgi-bin/welcome.pl?page=search", 
			"TargetFrame=body", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
			"Snapshot=t3.inf", 
			"Mode=HTML", 
			LAST);
	end_transaction(tName, status);
	lr_think_time(4);
	
	tName = "04.reservations_(continue_1)";
	lr_start_transaction(tName);
		web_reg_save_param_ex(
			"ParamName=Flight",
			"LB=name=\"outboundFlight\" value=\"",
			"RB=\"",
			"Ordinal=1",
			LAST);
	
		//name="outboundFlight" value="450;1165;11/19/2021"
		/* continue1 */
		status=web_submit_data("reservations.pl", 
			"Action=http://localhost:1080/cgi-bin/reservations.pl", 
			"Method=POST", 
			"TargetFrame=", 
			"RecContentType=text/html", 
			"Referer=http://localhost:1080/cgi-bin/reservations.pl?page=welcome", 
			"Snapshot=t4.inf", 
			"Mode=HTML", 
			ITEMDATA, 
			"Name=advanceDiscount", "Value=0", ENDITEM, 
			"Name=depart", "Value={City1}", ENDITEM, 
			"Name=departDate", "Value={Date1}", ENDITEM, 
			"Name=arrive", "Value={City2}", ENDITEM, 
			"Name=returnDate", "Value={Date2}", ENDITEM, 
			"Name=numPassengers", "Value={Passengers}", ENDITEM, 
			"Name=seatPref", "Value={seatPreference}", ENDITEM, 
			"Name=seatType", "Value={seat_Type}", ENDITEM, 
			"Name=.cgifields", "Value=roundtrip", ENDITEM, 
			"Name=.cgifields", "Value=seatType", ENDITEM, 
			"Name=.cgifields", "Value=seatPref", ENDITEM, 
			"Name=findFlights.x", "Value=72", ENDITEM, 
			"Name=findFlights.y", "Value=17", ENDITEM, 
			LAST);
	end_transaction(tName, status);
	lr_think_time(4);
	
		tName = "05.choice_of_4_tickets_(continue_2)";
		lr_start_transaction(tName);
		/* continue2 */

		status=web_submit_data("reservations.pl_2", 
			"Action=http://localhost:1080/cgi-bin/reservations.pl", 
			"Method=POST", 
			"TargetFrame=", 
			"RecContentType=text/html", 
			"Referer=http://localhost:1080/cgi-bin/reservations.pl", 
			"Snapshot=t5.inf", 
			"Mode=HTML", 
			ITEMDATA, 
			"Name=outboundFlight", "Value={Flight}", ENDITEM, 
			"Name=numPassengers", "Value={Passengers}", ENDITEM, 
			"Name=advanceDiscount", "Value=0", ENDITEM, 
			"Name=seatType", "Value={seat_Type}", ENDITEM, 
			"Name=seatPref", "Value={seatPreference}", ENDITEM, 
			"Name=reserveFlights.x", "Value=72", ENDITEM, 
			"Name=reserveFlights.y", "Value=10", ENDITEM, 
			LAST);
	end_transaction(tName, status);
	lr_think_time(4);
	
		tName = "06.Payment_Details_(continue_3)";
		lr_start_transaction(tName);
		/* continue3 */
		status=web_submit_data("reservations.pl_3", 
			"Action=http://localhost:1080/cgi-bin/reservations.pl", 
			"Method=POST", 
			"TargetFrame=", 
			"RecContentType=text/html", 
			"Referer=http://localhost:1080/cgi-bin/reservations.pl", 
			"Snapshot=t6.inf", 
			"Mode=HTML", 
			ITEMDATA, 
			"Name=firstName", "Value=Jojo", ENDITEM, 
			"Name=lastName", "Value=Bean", ENDITEM, 
			"Name=address1", "Value=", ENDITEM, 
			"Name=address2", "Value=", ENDITEM, 
			"Name=pass1", "Value=Jojo Bean", ENDITEM, 
			"Name=creditCard", "Value=", ENDITEM, 
			"Name=expDate", "Value=", ENDITEM, 
			"Name=oldCCOption", "Value=", ENDITEM, 
			"Name=numPassengers", "Value={Passengers}", ENDITEM, 
			"Name=seatType", "Value={seat_Type}", ENDITEM, 
			"Name=seatPref", "Value={seatPreference}", ENDITEM, 
			"Name=outboundFlight", "Value={Flight}", ENDITEM, 
			"Name=advanceDiscount", "Value=0", ENDITEM, 
			"Name=returnFlight", "Value=", ENDITEM, 
			"Name=JSFormSubmit", "Value=off", ENDITEM, 
			"Name=.cgifields", "Value=saveCC", ENDITEM, 
			"Name=buyFlights.x", "Value=75", ENDITEM, 
			"Name=buyFlights.y", "Value=2", ENDITEM, 
			LAST);
		end_transaction(tName, status);lr_think_time(4);

}
