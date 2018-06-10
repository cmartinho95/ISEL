Point start = elem.getStart();
Point end = ((Line)elem).getEnd();
int startX = start.getX();
int startY = start.getY();
int endX = end.getX();
int endY = end.getY();

int left, right, top, bottom;

if (startX < endX && endY > startY){
    left = startX;
    right = endX;
    top = startY;
    bottom = endY;
}
else if (startX > endX && endY > startY){
    left = endX;
    right = startX;
    top = startY;
    bottom = endY;
}
else if (startX < endX && endY < startY){
    left = startX;
    right = endX;
    top = endY;
    bottom = startY;
}
else{
    left = endX;
    right = startX;
    top = endY;
    bottom = startY;
}

c.drawRect(left, right, top, bottom, paint);
