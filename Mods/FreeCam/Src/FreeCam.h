#pragma once

#include <unordered_map>

#include "IPluginInterface.h"

#include <Glacier/ZEntity.h>
#include <Glacier/ZInput.h>

class FreeCam : public IPluginInterface
{
public:
	FreeCam();
	~FreeCam() override;

	void PreInit() override;
	void OnEngineInitialized() override;
	void OnDrawMenu() override;
	void OnDrawUI(bool p_HasFocus) override;

private:
	void OnFrameUpdate(const SGameUpdateEvent& p_UpdateEvent);
	void ToggleFreecam();

private:
	DEFINE_PLUGIN_DETOUR(FreeCam, bool, ZInputAction_Digital, ZInputAction* th, int a2);

private:
	volatile bool m_FreeCamActive;
	volatile bool m_ShouldToggle;
	volatile bool m_FreeCamFrozen;
	ZEntityRef m_OriginalCam;
	ZInputAction m_ToggleFreeCamAction;
	ZInputAction m_FreezeFreeCamActionGc;
	ZInputAction m_FreezeFreeCamActionKb;
	bool m_ControlsVisible;
	bool m_HasToggledFreecamBefore;
	std::unordered_map<std::string, std::string> m_PcControls;
	std::unordered_map<std::string, std::string> m_ControllerControls;
};

DEFINE_ZHM_PLUGIN(FreeCam)
