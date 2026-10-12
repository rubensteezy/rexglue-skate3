> [!NOTE]
> This is the **Skate 3 fork** of ReXGlue, used by the [Skate 3 recompilation](https://github.com/rubensteezy/skate3recomp). For general ReXGlue use, start from the official [rexglue/rexglue-sdk](https://github.com/rexglue/rexglue-sdk). See [About This Fork](#about-this-fork).

> [!CAUTION]
> This project is in early development. Expect things to not work quite right and there to be significant changes and breaking public API updates as development progresses. Contributions and feedback are welcome, but please be aware that the codebase is still evolving rapidly.

<h1 align="center">
  <br>
  <a href="https://github.com/rexglue/rexglue-sdk">
    <img src="https://github.com/rexglue/rexglue-media/blob/main/ReX_Banner.png" alt="ReXGlue banner">
  </a>
  <br>
  <br>
  <a href="https://discord.gg/CNTxwSNZfT">
    <img src="https://img.shields.io/badge/Discord-Join%20Server-5865F2?logo=discord&logoColor=white" alt="Discord">
  </a>
  <a href="https://github.com/rexglue/rexglue-sdk/stargazers">
    <img src="https://img.shields.io/github/stars/rexglue/rexglue-sdk" alt="rexglue-sdk stargazers">
  </a>
</h1>

ReXGlue converts Xbox 360 PowerPC code into portable C++ that runs natively on modern platforms.

ReXGlue is heavily rooted on the foundations of [Xenia](https://github.com/xenia-project), the Xbox 360 emulator. Rather than interpreting or JIT-compiling PPC instructions at runtime, ReXGlue takes a different path: it generates C++ source code ahead of time, an approach inspired by [XenonRecomp](https://github.com/hedge-dev/XenonRecomp) and [rexdex's recompiler](https://github.com/rexdex/recompiler).

Latest SDK builds and releases are published on [GitHub Releases](https://github.com/rexglue/rexglue-sdk/releases). Join the [Discord server](https://discord.gg/CNTxwSNZfT) for updates and share what you have created.

## About This Fork

This repository is the Skate 3-specific ReXGlue fork, consumed as the `third_party/rexglue-sdk` submodule of [rubensteezy/skate3recomp](https://github.com/rubensteezy/skate3recomp) and tracked on the `skate3-sdk-clean` branch. It continues [mchughalex/rexglue-skate3](https://github.com/mchughalex/rexglue-skate3), which went inactive along with the original Skate 3 recompilation in July 2026.

The fork follows ReXGlue releases by merging them in, and is currently on ReXGlue 0.10.0. On top of it, it carries the Skate 3 runtime, codegen, input and timing work, the Direct3D 12 and Vulkan backends used by the game's native renderer, the settings overlay, and the Linux and macOS fixes the game needs.

Changes made since the fork continued:

- **Direct3D 12 descriptor heap fix:** the shader-visible view heap's slot allocator now reuses freed ranges of any size, and trims idle binding tables under pressure. Before, every evicted multi-texture binding table leaked its slots during world streaming until the heap ran out and the device was removed. A failed table bind now skips the draw instead of sampling an unset table.
- **ReXGlue 0.10.0:** upstream v0.10.0 is merged in, bringing its XMA, threading, APC, SEH and GPU fixes, SDL3 windowing on every platform, and GPU emulation as the runtime-loaded `rexgpu-xenos` plugin. The plugin is built linkable (`REXGLUE_GPU_PLUGIN_LINKABLE`) because the game's native renderer calls into it. The fork was a squashed snapshot of 0.8.0 with no shared history; it now shares history with upstream, so later releases merge normally.
- **Fetchable imgui:** the imgui submodule pointed at commits that were never pushed to [ocornut/imgui](https://github.com/ocornut/imgui), so fresh recursive clones failed. It now comes from [rubensteezy/imgui](https://github.com/rubensteezy/imgui) (branch `rexglue-v1.92.5`): imgui 1.92.5 plus the `ImFontConfig::RasterizerGamma` coverage gamma that `src/ui/imgui_drawer.cpp` uses.

This fork is normally built as part of the game: the game's CMake adds it as a subdirectory, so there is no separate build step. Report Skate 3 issues, including ones caused by the SDK, on [rubensteezy/skate3recomp](https://github.com/rubensteezy/skate3recomp/issues). SDK changes land on `skate3-sdk-clean` here first, then the game repository bumps the submodule; see its [contributing guide](https://github.com/rubensteezy/skate3recomp/blob/main/CONTRIBUTING.md).

## Upstream Builds

The builds and releases below are official ReXGlue's, not this fork's.

| Channel | CI | Download |
| --- | --- | --- |
| Release | [![win-amd64](https://github.com/rexglue/rexglue-sdk/actions/workflows/build-win-amd64.yaml/badge.svg)](https://github.com/rexglue/rexglue-sdk/actions/workflows/build-win-amd64.yaml) [![linux-amd64](https://github.com/rexglue/rexglue-sdk/actions/workflows/build-linux-amd64.yaml/badge.svg)](https://github.com/rexglue/rexglue-sdk/actions/workflows/build-linux-amd64.yaml) [![linux-arm64](https://github.com/rexglue/rexglue-sdk/actions/workflows/build-linux-aarch64.yaml/badge.svg)](https://github.com/rexglue/rexglue-sdk/actions/workflows/build-linux-aarch64.yaml) | [Latest stable](https://github.com/rexglue/rexglue-sdk/releases/latest) |
| Nightly | [![nightly](https://github.com/rexglue/rexglue-sdk/actions/workflows/nightly.yaml/badge.svg)](https://github.com/rexglue/rexglue-sdk/actions/workflows/nightly.yaml) | [Latest pre-release](https://github.com/rexglue/rexglue-sdk/releases?q=prerelease%3Atrue) |

## Quickstart

For quick start guide, full CLI reference, and config file options, see the [wiki](https://github.com/rexglue/rexglue-sdk/wiki).

# **Disclaimer**
ReXGlue is not affiliated with nor endorsed by Microsoft or Xbox. It is an independent project created for educational and development purposes. All trademarks and copyrights belong to their respective owners. 

This project is not intended to promote piracy nor unauthorized use of copyrighted material. Any misuse of this software to endorse or enable this type of activity is strictly prohibited.


# Credits

## ReXGlue
- [Tom (crack)](https://github.com/tomcl7) - Project Founder
- [Loreaxe](https://github.com/Loreaxe) - Linux Contributor
- [mystixor](https://github.com/Mystixor) - Windows Contributor
- [Graine25](https://github.com/Graine25) - Project Support
- [Carlos Estrague (mrcmunir)](https://github.com/mrcmunir) - Linux / ARM64 Contributor
- [sanjay900](https://github.com/sanjay900) - Linux / SDL Contributor
- [Toby](https://github.com/TbyDtch) - Project Support
- [Roxxsen](https://github.com/Roxxsen) - CI/CD Contributor

The list above is not exhaustive. Thanks to everyone in the ReXGlue community who contributes code, files issues, tests builds, and keeps the project moving.

## Skate 3 Fork
- [mchughalex](https://github.com/mchughalex) - Original Skate 3 fork: runtime, native renderer backends, and platform fixes
- [rubensteezy](https://github.com/rubensteezy) - Fork maintenance since October 2026

## Very Special Thank You:
- [Project Xenia](https://github.com/xenia-project/xenia/tree/master/src/xenia) - Their invaluable work on Xbox 360 emulation laid the groundwork for ReXGlue's development. This project (and numerous others) would not exist without their hard work and dedication.
- [XenonRecomp](https://github.com/hedge-dev/XenonRecomp) - For pioneering the modern static recompilation approach for Xbox 360. A lot of the codegen analysis logic and instruction translations are based on their work. Thank you!
- [rexdex's recompiler](https://github.com/rexdex/recompiler) - The OG static recompiler for Xbox 360. 
- Many others in the Xbox 360 homebrew and modding communities whose work and research have contributed to the collective knowledge that makes projects like this possible.
