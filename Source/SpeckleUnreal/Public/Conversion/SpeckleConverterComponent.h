
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "SpeckleConverterComponent.generated.h"


class ITransport;
class ISpeckleConverter;
class UBase;
class UAggregateConverter;
struct FSlowTask;

/**
 * An Actor Component for encapsulating recursive conversion of Speckle Objects
 */
UCLASS(ClassGroup=(Speckle), meta=(BlueprintSpawnableComponent))
class SPECKLEUNREAL_API USpeckleConverterComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	
	// Array of converters
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Speckle|Conversion")
	UAggregateConverter* SpeckleConverter;
	
	// Sets default values for this component's properties
	USpeckleConverterComponent();
	
	// Converts the given Base and all children into native actors.
	UFUNCTION(BlueprintCallable, Category="Speckle|Conversion")
	UPARAM(DisplayName = "RootActor") AActor* RecursivelyConvertToNative(AActor* AOwner, const UBase* Base,
		       const TScriptInterface<ITransport>& LocalTransport, bool DisplayProgressBar, TArray<AActor*>& OutActors);
		
	UFUNCTION(BlueprintCallable, Category="Speckle|Conversion")
	virtual void FinishConversion();
	
protected:

	virtual AActor* RecursivelyConvertToNative_Internal(AActor* AOwner, const UBase* Base, const TScriptInterface<ITransport>& LocalTransport, FSlowTask* Task, TArray<AActor*>& OutActors);
	
	virtual void ConvertChild(const TSharedPtr<FJsonValue> Object, AActor* AOwner, const TScriptInterface<ITransport>& LocalTransport, FSlowTask* Task, TArray<AActor*>& OutActors);
	
	UFUNCTION(BlueprintCallable, Category="Speckle|Conversion")
	virtual void AttachConvertedToOwner(AActor* AOwner, const UBase* Base, UObject* Converted);
};


