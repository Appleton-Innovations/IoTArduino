% Channel ID to read data from 
readChannelID = 1408553; 
% Humidity Field ID 
ldrFieldID = 3; 

% Channel Read API Key 
% If your channel is private, then enter the read API Key between the '' below: 
readAPIKey = '69WF96JF9S48HJ1H'; 

% GetLight sensor data for the last 60 minutes from the MathWorks weather 
% station channel. Learn more about the THINGSPEAKREAD function by going to 
% the Documentation tab on the right side pane of this page. 

ldrValues = thingSpeakRead(readChannelID,'Fields',ldrFieldID,'NumMinutes',60,'ReadKey',readAPIKey); 
disp(ldrValues);
% Calculate the average Light Intensity values
avgldr = mean(ldrValues); 
display(avgldr,'Average Light Intenisty'); 
x=ldrValues;
e=mean(x);
si=std(x);
z=(x-e)/si;
display(z,'Z SCore Values');
plot(z)
output=[]
output1=[]
k=[]
for i=1:length(z)
    if(z(i)<=3 && z(i)>=-3)
        output=[output i];
        k=[k 0];
    else
       k=[k 1];
       output1=[output1,i];
    end
end
w=x(output)
disp(k)
w1=x(output1)
display(w1,'ouliers in Light data'); 
length(w1)
