#include "fmgl.h"

FMGL_DriverContext FMGL_AttachToDriver
(
	void* deviceContext,
	uint16_t (*GetWidth) (void),
	uint16_t (*GetHeight) (void),
	void (*SetActiveColor) (void* deviceContext, FMGL_ColorStruct color),
	void (*DrawPixel) (void* deviceContext, uint16_t x, uint16_t y),
	FMGL_ColorStruct (*GetPixel) (void* deviceContext, uint16_t x, uint16_t y),
	void (*PushFramebuffer) (void* deviceContext)
)
{
	FMGL_DriverContext context;

	context.DeviceContext = deviceContext;
	context.GetWidth = GetWidth;
	context.GetHeight = GetHeight;
	context.SetActiveColor = SetActiveColor;
	context.DrawPixel = DrawPixel;
	context.GetPixel = GetPixel;
	context.PushFramebuffer = PushFramebuffer;

	/* Maximal coordinates */
	context.MaxX = context.GetWidth() - 1;
	context.MaxY = context.GetHeight() - 1;

	return context;
}

void FMGL_SetActiveColor(FMGL_DriverContext* context, FMGL_ColorStruct color)
{
	context->ActiveColor = color;
	context->SetActiveColor(context->DeviceContext, context->ActiveColor);
}

FMGL_ColorStruct FMGL_GetActiveColor(FMGL_DriverContext* context)
{
	return context->ActiveColor;
}

void FMGL_DrawPixel (FMGL_DriverContext* context, uint16_t x, uint16_t y)
{
	if (x > context->MaxX || y > context->MaxY)
	{
		return;
	}

	context->DrawPixel(context->DeviceContext, x, y);
}

FMGL_ColorStruct FMGL_GetPixel(FMGL_DriverContext* context, uint16_t x, uint16_t y)
{
	FMGL_ColorStruct result;
	result.R = 0;
	result.G = 0;
	result.B = 0;

	if (x > context->MaxX || y > context->MaxY)
	{
		return result;
	}

	return context->GetPixel(context->DeviceContext, x, y);
}

void FMGL_PushFramebuffer (FMGL_DriverContext* context)
{
	context->PushFramebuffer(context->DeviceContext);
}

uint16_t FMGL_GetDisplayWidth(FMGL_DriverContext* context)
{
	return context->GetWidth();
}

uint16_t FMGL_GetDisplayHeight(FMGL_DriverContext* context)
{
	return context->GetHeight();
}

bool FMGL_IsActiveXBMPixel(FMGL_XBMStruct* image, uint16_t x, uint16_t y)
{
	if (x >= image->Width || y >= image->Height)
	{
		return false;
	}

	uint16_t bytesPerRow = image->Width / FMGL_BITS_PER_BYTE; /* Round down */
	if (0 != (image->Width % FMGL_BITS_PER_BYTE)) /* Do we have non completely filled byte at rightmost position in row*/
	{
		bytesPerRow ++;
	}

	uint32_t index = y * bytesPerRow + x / FMGL_BITS_PER_BYTE;
	uint8_t mask = (1 << (x % FMGL_BITS_PER_BYTE));

	if (0 != (image->Raster[index] & mask))
	{
		return true; /* To be sure that 0xFF is returned */
	}
	else
	{
		return false;
	}
}

