/*
             LUFA Library
     Copyright (C) Dean Camera, 2011.

  dean [at] fourwalledcubicle [dot] com
           www.lufa-lib.org
*/

/*
  Copyright 2011  Dean Camera (dean [at] fourwalledcubicle [dot] com)

  Permission to use, copy, modify, distribute, and sell this
  software and its documentation for any purpose is hereby granted
  without fee, provided that the above copyright notice appear in
  all copies and that both that the copyright notice and this
  permission notice and warranty disclaimer appear in supporting
  documentation, and that the name of the author not be used in
  advertising or publicity pertaining to distribution of the
  software without specific, written prior permission.

  The author disclaim all warranties with regard to this
  software, including all implied warranties of merchantability
  and fitness.  In no event shall the author be liable for any
  special, indirect or consequential damages or any damages
  whatsoever resulting from loss of use, data or profits, whether
  in an action of contract, negligence or other tortious action,
  arising out of or in connection with the use or performance of
  this software.
*/

/** \file
 *
 *  USB Device Descriptors, for library use when in USB device mode. Descriptors are special
 *  computer-readable structures which the host requests upon device enumeration, to determine
 *  the device's capabilities and functions.
 */

#include "Descriptors.h"

/** HID class report descriptor. This is a special descriptor constructed with values from the
 *  USBIF HID class specification to describe the reports and capabilities of the HID device. This
 *  descriptor is parsed by the host and its contents used to determine what data (and in what encoding)
 *  the device will send, and what it may be sent back from the host. Refer to the HID specification for
 *  more details on HID report descriptors.
 */
const USB_Descriptor_HIDReport_Datatype_t PROGMEM KeyboardReport[] =
{
	/* Use the HID class driver's standard Keyboard report.
	 *   Max simultaneous keys: 6
	 */
	HID_DESCRIPTOR_KEYBOARD(6)
};

USB_Descriptor_HIDReport_Datatype_t PROGMEM MouseReport[] =
{
	HID_RI_USAGE_PAGE(8, 0x01),                                           /* Usage Page (Generic Desktop)                    */
	HID_RI_USAGE(8, 0x02),                                                /* Usage (Mouse)                                   */
	HID_RI_COLLECTION(8, 0x1),                                            /* Collection (Application)                        */
	HID_RI_USAGE(8, 0x01),                                                /*   Usage (Pointer)                               */
	HID_RI_COLLECTION(8, 0x00),                                           /*   Collection (Physical)                         */
	HID_RI_REPORT_COUNT(8, 0x05),                                         /*     Report Count (5)                            */
	HID_RI_REPORT_SIZE(8, 0x01),                                          /*     Report Size (1)                             */
	HID_RI_USAGE_PAGE(8, 0x09),                                           /*     Usage Page (Button)                         */
	HID_RI_USAGE_MINIMUM(8, 0x01),                                        /*     Usage Minimum (Button 1)                    */
	HID_RI_USAGE_MAXIMUM(8, 0x05),                                        /*     Usage Maximum (Button 5)                    */
	HID_RI_LOGICAL_MINIMUM(8, 0x00),                                      /*     Logical Minimum (0)                         */
	HID_RI_LOGICAL_MAXIMUM(8, 0x01),                                      /*     Logical Maximum (1)                         */
	HID_RI_INPUT(8, HID_IOF_DATA | HID_IOF_VARIABLE | HID_IOF_ABSOLUTE),  /*     Input (Data, Variable, Absolute)            */
	HID_RI_REPORT_COUNT(8, 0x01),                                         /*     Report Count (1)                            */
	HID_RI_REPORT_SIZE(8, 0x03),                                          /*     Report Size (3)                             */
	HID_RI_INPUT(8, HID_IOF_CONSTANT),                                    /*     Input (Constant)                            */
	HID_RI_REPORT_SIZE(8, 0x08),                                          /*     Report Size (8)                             */
	HID_RI_REPORT_COUNT(8, 0x02),                                         /*     Report Count (2)                            */
	HID_RI_USAGE_PAGE(8, 0x01),                                           /*     Usage Page (Generic Desktop Control)        */
	HID_RI_USAGE(8, 0x30),                                                /*     Usage X                                     */
	HID_RI_USAGE(8, 0x31),                                                /*     Usage Y                                     */
	HID_RI_LOGICAL_MINIMUM(8, 0x81),                                      /*     Logical Minimum (-127)                      */
	HID_RI_LOGICAL_MAXIMUM(8, 0x7F),                                      /*     Logical Maximum (127)                       */
	HID_RI_INPUT(8, HID_IOF_DATA | HID_IOF_VARIABLE | HID_IOF_RELATIVE),  /*     Input (Data, Variable, Relative)            */
	HID_RI_END_COLLECTION(0),                                             /*   End Collection                                */
	HID_RI_END_COLLECTION(0),                                             /* End Collection                                  */
};

/* mouse wheel looks like:
	                                                                      // ------------------------------  Vertical wheel
	HID_RI_USAGE(8, 0x38),                                                //          USAGE (Wheel)
	HID_RI_LOGICAL_MINIMUM(8, 0x81),                                      //          LOGICAL_MINIMUM (-127)
	HID_RI_LOGICAL_MAXIMUM(8, 0x7F),                                      //          LOGICAL_MAXIMUM (127)
	HID_RI_PHYSICAL_MINIMUM(8, 0),                                        //          PHYSICAL_MINIMUM (0)        - reset physical
	HID_RI_PHYSICAL_MAXIMUM(8, 0),                                        //          PHYSICAL_MAXIMUM (0)
	HID_RI_REPORT_SIZE(8, 0x08),                                          //          REPORT_SIZE (8)
	HID_RI_INPUT(8, HID_IOF_DATA | HID_IOF_VARIABLE | HID_IOF_RELATIVE),  //          INPUT (Data,Var,Rel)
*/

/** Device descriptor structure. This descriptor, located in FLASH memory, describes the overall
 *  device characteristics, including the supported USB version, control endpoint size and the
 *  number of device configurations. The descriptor is read out by the USB host when the enumeration
 *  process begins.
 */
const USB_Descriptor_Device_t PROGMEM DeviceDescriptor =
{
	.Header                 = {.Size = sizeof(USB_Descriptor_Device_t), .Type = DTYPE_Device},

	.USBSpecification       = VERSION_BCD(01.10),
	.Class                  = USB_CSCP_NoDeviceClass,
	.SubClass               = USB_CSCP_NoDeviceSubclass,
	.Protocol               = USB_CSCP_NoDeviceProtocol,

	.Endpoint0Size          = FIXED_CONTROL_ENDPOINT_SIZE,

	.VendorID               = 0x03EB,
	.ProductID              = 0x2043,
	.ReleaseNumber          = VERSION_BCD(00.01),

	.ManufacturerStrIndex   = 0x01,
	.ProductStrIndex        = 0x02,
	.SerialNumStrIndex      = NO_DESCRIPTOR,

	.NumberOfConfigurations = FIXED_NUM_CONFIGURATIONS
};

/** Configuration descriptor structure. This descriptor, located in FLASH memory, describes the usage
 *  of the device in one of its supported configurations, including information about any device interfaces
 *  and endpoints. The descriptor is read out by the USB host during the enumeration process when selecting
 *  a configuration so that the host may correctly communicate with the USB device.
 */
const USB_Descriptor_Configuration_t PROGMEM ConfigurationDescriptor =
{
	.Config =
	{
		.Header                 = {.Size = sizeof(USB_Descriptor_Configuration_Header_t), .Type = DTYPE_Configuration},

		.TotalConfigurationSize = sizeof(USB_Descriptor_Configuration_t),
		.TotalInterfaces        = 2,

		.ConfigurationNumber    = 1,
		.ConfigurationStrIndex  = NO_DESCRIPTOR,

		.ConfigAttributes       = (USB_CONFIG_ATTR_BUSPOWERED | USB_CONFIG_ATTR_SELFPOWERED),

		.MaxPowerConsumption    = USB_CONFIG_POWER_MA(100)
	},

	.HID1_KeyboardInterface =
	{
		.Header                 = {.Size = sizeof(USB_Descriptor_Interface_t), .Type = DTYPE_Interface},

		.InterfaceNumber        = 0x00,
		.AlternateSetting       = 0x00,

		.TotalEndpoints         = 1,

		.Class                  = HID_CSCP_HIDClass,
		.SubClass               = HID_CSCP_BootSubclass,
		.Protocol               = HID_CSCP_KeyboardBootProtocol,

		.InterfaceStrIndex      = NO_DESCRIPTOR
	},

	.HID1_KeyboardHID =
	{
		.Header                 = {.Size = sizeof(USB_HID_Descriptor_HID_t), .Type = HID_DTYPE_HID},

		.HIDSpec                = VERSION_BCD(01.11),
		.CountryCode            = 0x00,
		.TotalReportDescriptors = 1,
		.HIDReportType          = HID_DTYPE_Report,
		.HIDReportLength        = sizeof(KeyboardReport)
	},

	.HID1_ReportINEndpoint =
	{
		.Header                 = {.Size = sizeof(USB_Descriptor_Endpoint_t), .Type = DTYPE_Endpoint},

		.EndpointAddress        = (ENDPOINT_DESCRIPTOR_DIR_IN | KEYBOARD_IN_EPNUM),
		.Attributes             = (EP_TYPE_INTERRUPT | ENDPOINT_ATTR_NO_SYNC | ENDPOINT_USAGE_DATA),
		.EndpointSize           = KEYBOARD_EPSIZE,
		.PollingIntervalMS      = 0x01
	},

	.HID2_MouseInterface =
	{
		.Header                 = {.Size = sizeof(USB_Descriptor_Interface_t), .Type = DTYPE_Interface},

		.InterfaceNumber        = 0x01,
		.AlternateSetting       = 0x00,

		.TotalEndpoints         = 1,

		.Class                  = HID_CSCP_HIDClass,
		.SubClass               = HID_CSCP_BootSubclass,
		.Protocol               = HID_CSCP_MouseBootProtocol,

		.InterfaceStrIndex      = NO_DESCRIPTOR
	},

	.HID2_MouseHID =
	{
		.Header                 = {.Size = sizeof(USB_HID_Descriptor_HID_t), .Type = HID_DTYPE_HID},

		.HIDSpec                = VERSION_BCD(01.11),
		.CountryCode            = 0x00,
		.TotalReportDescriptors = 1,
		.HIDReportType          = HID_DTYPE_Report,
		.HIDReportLength        = sizeof(MouseReport)
	},

	.HID2_ReportINEndpoint =
	{
		.Header                 = {.Size = sizeof(USB_Descriptor_Endpoint_t), .Type = DTYPE_Endpoint},

		.EndpointAddress        = (ENDPOINT_DESCRIPTOR_DIR_IN | MOUSE_IN_EPNUM),
		.Attributes             = (EP_TYPE_INTERRUPT | ENDPOINT_ATTR_NO_SYNC | ENDPOINT_USAGE_DATA),
		.EndpointSize           = MOUSE_EPSIZE,
		.PollingIntervalMS      = 0x01
	}

};

/** Language descriptor structure. This descriptor, located in FLASH memory, is returned when the host requests
 *  the string descriptor with index 0 (the first index). It is actually an array of 16-bit integers, which indicate
 *  via the language ID table available at USB.org what languages the device supports for its string descriptors.
 */
const USB_Descriptor_String_t PROGMEM LanguageString =
{
	.Header                 = {.Size = USB_STRING_LEN(1), .Type = DTYPE_String},

	.UnicodeString          = {LANGUAGE_ID_ENG}
};

/** Manufacturer descriptor string. This is a Unicode string containing the manufacturer's details in human readable
 *  form, and is read out upon request by the host when the appropriate string ID is requested, listed in the Device
 *  Descriptor.
 */
const USB_Descriptor_String_t PROGMEM ManufacturerString =
{
	.Header                 = {.Size = USB_STRING_LEN(5), .Type = DTYPE_String},

	.UnicodeString          = L"Candy"
};

/** Product descriptor string. This is a Unicode string containing the product's details in human readable form,
 *  and is read out upon request by the host when the appropriate string ID is requested, listed in the Device
 *  Descriptor.
 */
const USB_Descriptor_String_t PROGMEM ProductString =
{
	.Header                 = {.Size = USB_STRING_LEN(8), .Type = DTYPE_String},

	.UnicodeString          = L"Keyboard"
};

/** This function is called by the library when in device mode, and must be overridden (see library "USB Descriptors"
 *  documentation) by the application code so that the address and size of a requested descriptor can be given
 *  to the USB library. When the device receives a Get Descriptor request on the control endpoint, this function
 *  is called so that the descriptor details can be passed back and the appropriate descriptor sent back to the
 *  USB host.
 */
uint16_t CALLBACK_USB_GetDescriptor(const uint16_t wValue,
                                    const uint8_t wIndex,
                                    const void** const DescriptorAddress)
{
	const uint8_t  DescriptorType   = (wValue >> 8);
	const uint8_t  DescriptorNumber = (wValue & 0xFF);

	const void* Address = NULL;
	uint16_t    Size    = NO_DESCRIPTOR;

	switch (DescriptorType)
	{
		case DTYPE_Device:
			Address = &DeviceDescriptor;
			Size    = sizeof(USB_Descriptor_Device_t);
			break;
		case DTYPE_Configuration:
			Address = &ConfigurationDescriptor;
			Size    = sizeof(USB_Descriptor_Configuration_t);
			break;
		case DTYPE_String:
			switch (DescriptorNumber)
			{
				case 0x00:
					Address = &LanguageString;
					Size    = pgm_read_byte(&LanguageString.Header.Size);
					break;
				case 0x01:
					Address = &ManufacturerString;
					Size    = pgm_read_byte(&ManufacturerString.Header.Size);
					break;
				case 0x02:
					Address = &ProductString;
					Size    = pgm_read_byte(&ProductString.Header.Size);
					break;
			}

			break;
		case HID_DTYPE_HID:
			if (!(wIndex))
			{
				Address = &ConfigurationDescriptor.HID1_KeyboardHID;
				Size    = sizeof(USB_HID_Descriptor_HID_t);
			}
			else
			{
				Address = &ConfigurationDescriptor.HID2_MouseHID;
				Size    = sizeof(USB_HID_Descriptor_HID_t);
			}
			break;
		case HID_DTYPE_Report:
			if (!(wIndex))
			{
				Address = &KeyboardReport;
				Size    = sizeof(KeyboardReport);
			}
			else
			{
				Address = &MouseReport;
				Size    = sizeof(MouseReport);
			}

			break;
	}

	*DescriptorAddress = Address;
	return Size;
}
