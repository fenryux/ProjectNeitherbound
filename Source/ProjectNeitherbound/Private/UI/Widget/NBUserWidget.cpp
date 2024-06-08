// Copyright fenryux


#include "UI/Widget/NBUserWidget.h"

void UNBUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}
