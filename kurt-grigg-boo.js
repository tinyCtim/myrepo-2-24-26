
<!-- from a script by Kurt Grigg

// kurt-grigg.js - 2015 - lrb

pics=new Array();

pics[0]='http://primepuzzle.com/images/casper.0625.gif';
pics[1]='http://primepuzzle.com/images/casper.125.gif';
pics[2]='http://primepuzzle.com/images/casper.25.gif';
pics[3]='http://primepuzzle.com/images/casper.5.gif';
pics[4]='http://primepuzzle.com/images/casper.gif';

load=new Array();

function PreLoad(){
 for(i=0; i < pics.length; i++) {
  load[i]=new Image();load[i].src=pics[i];
 }}

PreLoad();
BY=-22;
BX=-17;
NS4=(document.layers);
NS6=(document.getElementById&&!document.all);
IE4=(document.all);
L=null;
if (NS4){
document.write("<LAYER NAME='netscape' LEFT=0 TOP=0><img name='n' src="+load[0].src+"></LAYER>");
}
if (NS6){
document.write("<img id='n6' src='"+load[0].src+"' style='position:absolute;top:0px;left:0px'>");
}
if (IE4){
document.write("<div style='position:absolute;top:0px;left:0px'><div style='position:relative'>");
document.write("<img id='explorer' src='"+load[0].src+"' style='position:absolute;top:0px;left:0px'>");
document.write("</div></div>")
}
R=0,PB=0,C2=0,C1=0,Y=0,X=0,D=0,VB=0,HB=0;
Y=10;X=10;D=Math.floor(Math.random()*60+10);

function Curve(){
plusMinus=new Array(1,-1,0,2,-2,3,-3,0,1,-1)
R = plusMinus[Math.floor(Math.random()*plusMinus.length)];
}

function picSwap(){
if (C2 >= pics.length)C2=0;
if (NS4)document.layers['netscape'].document.images['n'].src=pics[C2];
if (NS6)document.getElementById("n6").src=pics[C2];
if (IE4)explorer.src=pics[C2];
}

function MoveRandom(){
C1++;
if (C1==50){C2++;Curve();picSwap();C1=0}
setTimeout('MoveRandom()',200);
var H=(NS6||NS4)?window.innerHeight:document.body.clientHeight;
var W=(NS6||NS4)?window.innerWidth:document.body.clientWidth;
var YS=(NS6||NS4)?window.pageYOffset:document.body.scrollTop;
var XS=(NS6||NS4)?window.pageXOffset:document.body.scrollLeft;
PB=D+=R;
y = 3*Math.sin(PB*Math.PI/180);
x = 3*Math.cos(PB*Math.PI/180);
if (D < 0) D+=360;
Y+=y;
X+=x;
VB=180-D;
HB=0-D;
if ((Y < 1) && (X < 1)) {Y=1;X=1;D=45;}
if ((Y < 1) && (X > W+BX)) {Y=1;X=W+BX;D=135;}
if ((Y > H+BY) && (X < 1)) {Y=H+BY;X=1;D=315;}
if ((Y > H+BY) && (X > W+BX)) {Y=H+BY;X=W+BX;D=225;}
if (Y < 1) {Y=1;D=HB;}
if (Y > H+BY) {Y=H+BY;D=HB;}
if (X < 1) {X=1;D=VB;}
if (X > W+BX) {X=W+BX;D=VB;}
if (NS4)L=document.netscape;
if (NS6)L=document.getElementById("n6").style;
if (IE4)L=explorer.style;
L.top=Y+YS;
L.left=X+XS;
}
window.onload=MoveRandom;
//-->

