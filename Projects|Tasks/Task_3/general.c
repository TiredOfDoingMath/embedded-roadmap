
//***function to reset all EXTICR modes***

//each register (1,2,3,4) corresponds to (0,1,2,3) in the array
// any register can configure 4 distinct pins to A,B,C,D,F
// pins in each register do not overlap 


//if we want to change between GPIO peripherals
// we can call this function first to set a quadrant
// to peripheral A which has value 0x00
void resetA(uint8_t pos, uint8_t quad) {
    switch (quad) {
    case 1:
    EXTI -> EXTICR[pos] &= ~(0xFUL << 0);
    if(pos == 0) {
      EXTI -> EXTICR[pos] &= ~(1UL << 5);
    }
    break;
    case 2:
     EXTI -> EXTICR[pos] &= ~(0xFUL << 8);
    if(pos == 0) {
      EXTI -> EXTICR[pos] &= ~(1UL << 13);
    }
    break;
    case 3:
    EXTI -> EXTICR[pos] &= ~(0xFUL << 16);
    if(pos == 0) {
      EXTI -> EXTICR[pos] &= ~(1UL << 21);
    }
    break;
    case 4:
    EXTI -> EXTICR[pos] &= ~(0xFUL << 24);
    if(pos == 0) {
      EXTI -> EXTICR[pos] &= ~(1UL << 29);
    }
    break;
    default:
  }
}

void setB(uint8_t pos, uint8_t quad) {
  switch (quad) {
    case 1:
    EXTI -> EXTICR[pos] |= (1UL << 0);
    break;
    case 2:
    EXTI -> EXTICR[pos] |= (1UL << 8);
    break;
    case 3:
    EXTI -> EXTICR[pos] |= (1UL << 16);
    break;
    case 4:
    EXTI -> EXTICR[pos] |= (1UL << 24);
    break;
    default:
  }
}

void setC(uint8_t pos, uint8_t quad) {
  switch (quad) {
    case 1:
    EXTI -> EXTICR[pos] |= (1UL << 1);
    break;
    case 2:
    EXTI -> EXTICR[pos] |= (1UL << 9);
    break;
    case 3:
    EXTI -> EXTICR[pos] |= (1UL << 17);
    break;
    case 4:
    EXTI -> EXTICR[pos] |= (1UL << 25);
    break;
    default:
  }
}

void setD(uint8_t pos, uint8_t quad) {
  switch (quad) {
    case 1:
    EXTI -> EXTICR[pos] |= (1UL << 2);
    break;
    case 2:
    EXTI -> EXTICR[pos] |= (1UL << 10);
    break;
    case 3:
    EXTI -> EXTICR[pos] |= (1UL << 18);
    break;
    case 4:
    EXTI -> EXTICR[pos] |= (1UL << 26);
    break;
    default:
  }
}

void setF(uint8_t quad) {
  switch (quad) {
    case 1:
    EXTI -> EXTICR[0] |= (1UL << 2);
    break;
    case 2:
    EXTI -> EXTICR[0] |= (1UL << 10);
    break;
    case 3:
    EXTI -> EXTICR[0] |= (1UL << 18);
    break;
    case 4:
    EXTI -> EXTICR[0] |= (1UL << 26);
    break;
    default:
  }
}
