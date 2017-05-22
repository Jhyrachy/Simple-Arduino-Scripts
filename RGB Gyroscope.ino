const int greenPin= 9;
const int bluePin= 8;
const int redPin= 10;

const int xpin = A1;
const int ypin = A2;
const int zpin = A3;

const float zero_G = 338.0; //ADXL335 power supply by Vs 3.3V:3.3V/5V*1024=676/2=338,by default is 338
const float zero_Gx=331.5;//the zero g output of x axis
const float zero_Gy=329.5;//the zero g output of y axis
const float zero_Gz=340.0;//the zero g output of z axis
const float scale = 67.6;

const int transf = 0.008;
const int maxval = 255;

void setup()
{
  pinMode(greenPin,OUTPUT);  //initialize the greenPin as output
  pinMode(bluePin, OUTPUT);  //initialize the bluePin as output
  pinMode(redPin, OUTPUT);  //initialize the redPin as output

  Serial.begin(9600);
}

void loop()
{
  float x = analogRead(xpin);  //read from xpin
  delay(1); //
  float y = analogRead(ypin);  //read from ypin
  delay(1);  
  float z = analogRead(zpin);  //read from zpin

  float x2 = ((x - zero_Gx)/scale)+1;
  float y2 = ((y - zero_Gx)/scale)+1;
  float z2 = ((z - zero_Gx)/scale)+1;

  float colorpinred = x2/0.008;
  float colorpingreen = y2/0.008;
  float colorpinblue = z2/0.008;
   
  int colredabs = abs((int)colorpinred);
    if(colredabs > maxval){
      colredabs = colredabs - maxval;
    }
  int colgreendabs = abs((int)colorpingreen);
    if(colgreendabs > maxval){
      colgreendabs = colgreendabs - maxval;
    }
  int colblueabs = abs((int)colorpinblue);
    if(colblueabs > maxval){
      colblueabs = colblueabs - maxval;
    }

  
  color(colredabs, colgreendabs, colblueabs); 

  Serial.print(colorpinred);  //print x value on serial monitor
  Serial.print("\t");
  Serial.print(colredabs);  //print x value on serial monitor
  Serial.print("\t");
  Serial.print(x2);  //print x value on serial monitor
  Serial.print("\n");
  Serial.print(colorpingreen);  //print y value on serial monitor
  Serial.print("\t");
  Serial.print(colgreendabs);  //print y value on serial monitor
  Serial.print("\t");
  Serial.print(y2);  //print x value on serial monitor
  Serial.print("\n");
  Serial.print(colorpinblue);  //print z value on serial monitor
  Serial.print("\t");
  Serial.print(colblueabs);  //print z value on serial monitor
  Serial.print("\t");
  Serial.print(z2);  //print x value on serial monitor
  Serial.print("\n");
  Serial.print("\n");
  delay(100); 
 
}

void color (unsigned char red, unsigned char green, unsigned char blue)     // the color generating function  
{    
  analogWrite(redPin, red);   
  analogWrite(greenPin, green); 
  analogWrite(bluePin, blue); 
}
