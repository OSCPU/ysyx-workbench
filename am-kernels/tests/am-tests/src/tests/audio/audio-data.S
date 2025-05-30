.section .data
.global audio_payload, audio_payload_end
.p2align 3
audio_payload:
.incbin "src/tests/audio/little-star.pcm"
audio_payload_end:
