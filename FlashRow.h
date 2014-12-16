/*
 * FlashRow.h
 *
 *  Created on: 10.12.2014
 *      Author: Jochen
 */

#ifndef FLASHROW_H_
#define FLASHROW_H_


#define FLASH_ROW_4(seg0,seg1,seg2,seg3) \
    ((seg0<<0)|(seg1<<1)|(seg2<<2)|(seg3<<3))

#define FLASH_ROW_6(seg0,seg1,seg2,seg3,seg4,seg5) \
    ((seg0<<0)|(seg1<<1)|(seg2<<2)|(seg3<<3)|(seg4<<4)|(seg5<<5))

#define FLASH_ROW_10(seg0,seg1,seg2,seg3,seg4,seg5,seg6,seg7,seg8,seg9) \
    ((seg0<<0)|(seg1<<1)|(seg2<<2)|(seg3<<3)|(seg4<<4)|(seg5<<5)|(seg6<<6)|(seg7<<7)|(seg8<<8)|(seg9<<9))


#endif /* FLASHROW_H_ */
