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
	context->SetActiveColor(context->DeviceContext, color);
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

